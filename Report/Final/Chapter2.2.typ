== Giao diện

=== Màn hình chính
Thông

=== Cài đặt
Thông

=== Các màn hình lưu, tải và phát lại ván đấu
Các màn hình này đều có cấu trúc tương tự nhau, gồm:
    - Danh sách các file: hiển thị danh sách các file đã lưu, trang hiện tại và tổng số trang.
    - Ô nhập văn bản: cho phép người chơi nhập tên file cần lưu, tải hoặc phát lại hoặc tìm kiếm trong danh sách các file đã lưu.
    - Các hướng dẫn: hiện các nút và chức năng tương ứng.
Vì sự tương tự này, em đã tạo một class chung là `SaveLoadScreenViewModel` bao gồm các trạng thái và chức năng chung của các màn hình này. class nằm trong ```Cpp namespace Common``` trong file `Common.h` và `Common.cpp`.

*Interface(Đã loại bỏ một số hàm nhỏ):*
```
using namespace std::filesystem::path;
typedef std::vector<std::pair<std::wstring, path>> OptionList;

class SaveLoadScreenViewModel {
    // Các trạng thái chung
    path allOptionsDir;
    int selected = 0;
    int currentPage = 0;
    bool isSearching = 0;
    int maxPage = 0;
    // Các file đã tìm được trong thư mục
    OptionList allOptions;
    // Dữ liệu để hiển thị lên màn hình
    std::vector<View::Option> options;
    std::wstring pageIndicator; // Hiện số trang
    std::wstring searchInput; // Nội dung của ô tìm kiếm
    SaveLoadScreenViewModel(path dir = Constants::SAVE_PATH)
    {
        allOptionsDir = dir;
    }

    void ReloadAllOptions()
    { // Tải lại danh sách các file
        LoadAllOptions(allOptionsDir);
        UpdatePage(currentPage);
    }

    void LoadAllOptions(path dir); // Đọc tất cả các file trong thư mục
    bool Search(); // Tìm kiếm các file có tên chứa chuỗi searchInput
    // Tạo ra một hàm để chạy khi người chơi thay đổi nội dung ô tìm kiếm
    std::function<void(const std::wstring&)> onSearchValueChange(
        const std::function<void(void)>& callback
    );
};
```

*Usage:*
```
// Sử dụng class trong màn hình lưu
class SaveScreenState : public Common::SaveLoadScreenViewModel {
  public:
    bool Save(const GameState& currentGameState);
};
```

==== Hiển thị danh sách các file đã lưu
Để hiển thị danh sách các file đã lưu, trò chơi cần tải danh sách các file đã lưu trong một thư mục nhất định, sau đó sắp xếp tăng dần theo thời gian rồi chỉnh sửa một chút để hiển thị lên phần "Danh sách các file".

*Implementation:*
```
void Common::SaveLoadScreenViewModel::LoadAllOptions(path dir)
{
    auto availableLoadFiles 
        = SaveLoad::DiscoverSaveFiles(dir);
    std::sort(
        availableLoadFiles.begin(),
        availableLoadFiles.end(),
        [](const FileHandle::FileDetail& a, 
           const FileHandle::FileDetail& b) {
            return a.lastModified > b.lastModified;
        }
    );

    allOptions.clear();
    allOptions.reserve(availableLoadFiles.size());

    for (auto& file : availableLoadFiles) {
        allOptions.emplace_back(
            Utils::CatStringSpaceBetween(
                50,
                file.filePath.filename(),
                Utils::filesystem_time_to_wstr_local
                                    (file.lastModified)
            ),
            file.filePath
        );
    }

    maxPage = allOptions.size() / 10 
            + bool(allOptions.size() % 10);
}
```

==== Ô tìm kiếm hoặc nhập tên
Ô tìm kiếm sử dụng thành phần giao diện Input để đọc đầu vào của người dùng. Mỗi khi người dùng thay đổi nội dung ô tìm kiếm, trò chơi sẽ sắp xếp các file có tên chứa chuỗi mà người dùng đã nhập lên đầu và cập nhật lại danh sách các file hiển thị lên màn hình. Để làm được điều đó, em đã tạo một hàm để tìm kiếm các file có tên chứa chuỗi mà người dùng đã nhập, hàm sẽ duyệt qua danh sách các file đã lưu, rồi sắp xếp đưa các file phù hợp lên đầu danh sách rồi cập nhật lên màn hình. Việc tìm kiếm mỗi lần người dùng nhập một ký tự sẽ làm chậm trò chơi do phải liên tục vẽ lại danh sách lên màn hình, để giảm thiểu điều này, trước khi thực hiện việc sắp xếp, kiểm tra xem danh sách đã được sắp xếp hay chưa, nếu chưa thì mới sắp xếp.

*Implementation:*
```
struct SortTemporary {
    size_t foundIndex = 0;
    std::wstring name;
    size_t mapIndex = 0;
}

bool Common::SaveLoadScreenViewModel::Search()
{
    static auto cmp = [](
        const SortTemporary& a, 
        const SortTemporary& b
    ) {
        if (a.foundIndex != size_t(-1) 
            && b.foundIndex != size_t(-1)) 
        {
            return a.name > b.name;
        }

        if (a.foundIndex == b.foundIndex) {
            return a.name > b.name;
        }

        return a.foundIndex < b.foundIndex;
    };

    size_t n = allOptions.size();
    std::vector<SortTemporary> tmp;
    tmp.resize(n);

    for (size_t i = 0; i < n; i++) {
        auto ttt = allOptions[i].second.filename().wstring();
        tmp[i] = {ttt.find(searchInput), std::move(ttt), i};
    }
    // Kiểm tra xem danh sách có cần sắp xếp hay không
    if (std::is_sorted(tmp.begin(), tmp.end(), cmp)) {
        return 0;
    }

    std::sort(tmp.begin(), tmp.end(), cmp);

    OptionList vtmp;
    vtmp.resize(n);
    for (size_t i = 0; i < n; i++) {
        vtmp[i] = allOptions[tmp[i].mapIndex];
    }
    allOptions = vtmp;
    return 1;
}
```

==== Cách lưu và tải ván đấu
Trạng thái của một ván đấu trong trò chơi bao gồm các thông tin sau:
    - Thời gian chơi hoặc thời gian còn lại của mỗi người chơi, thời gian đã trôi qua
    - Thông tin của 2 người chơi: tên, avatar, điểm số
    - Chế độ, loại trò chơi, độ khó của AI, ai đi trước, kết cục của trò chơi
    - Các nước đi đã được thực hiện trong ván đấu
Các trạng thái ấy được gộp chung vào một `struct` như sau:
```
struct GameState {
    std::wstring playerNameOne;
    short playerTimeOne = 0;
    short playerScoreOne = 0;
    short playerAvatarOne = -1;

    std::wstring playerNameTwo;
    short playerTimeTwo = 0;
    short playerScoreTwo = 0;
    short playerAvatarTwo = -1;
    
    short gameType = 0;
    short gameMode = 0;
    short aiDifficulty = 0;
    bool playerOneFirst = 1;
    short gameTime = 0;
    short gameEnd = 0;
    std::vector<std::pair<short, short>> moveList;
};
```
Với những thông tin ấy, chúng em đã chọn cách lưu ván đấu dưới dạng file văn bản do sự tiện dụng của cách lưu này. Tuy nhiên, khi lưu bằng cách này thì người chơi có thể dễ dàng can thiệp vào file lưu gây ra một số tính huống không mong muốn, một điều khó tránh khỏi kể cả khi lưu bằng file nhị phân. 

Khi lưu ván đấu, hàm sẽ mở file với tên được người chơi nhập vào, sau đó ghi các thông tin của ván đấu vào file. Khi tải ván đấu, hàm sẽ mở file với tên được người chơi chọn, sau đó đọc các thông tin của ván đấu từ file.

Sau đây là chi tiết hàm lưu ván đấu:
*Implementation:*
```
bool SaveLoad::Save(
    const GameState& data,
    const std::wstring& name,
    const std::filesystem::path& dir
)
{
    auto file = FileHandle::OpenOutFile(dir.generic_wstring() + name);
    if (file.fail()) {
        return false;
    }
    file << data.playerNameOne << '\n';
    file << data.playerScoreOne << '\n';
    file << data.playerTimeOne << '\n';
    file << data.playerAvatarOne << '\n';

    file << data.playerNameTwo << '\n';
    file << data.playerScoreTwo << '\n';
    file << data.playerTimeTwo << '\n';
    file << data.playerAvatarTwo << '\n';

    file << data.gameMode << '\n';
    file << data.aiDifficulty << '\n';
    file << data.playerOneFirst << '\n';
    file << data.gameTime << '\n';
    file << data.gameEnd << '\n';

    for (auto& i : data.moveList) {
        file << i.first << ' ' << i.second << '\n';
    }

    if (file.fail()) {
        std::filesystem::remove(dir.generic_wstring() + name);
    }

    return !file.fail();
}
```
*Parameters:*
    - `data`: Trạng thái của ván đấu cần lưu
    - `name`: Tên của file lưu
    - `dir`: Đường dẫn của thư mục chứa file lưu

*Return:*
    - `true` #sym.arrow.r Lưu thành công
    - `false` #sym.arrow.r Lưu thất bại

Sau đây là chi tiết hàm tải ván đấu:

*Implementation:*
```
std::optional<GameState> 
SaveLoad::Load(
    const std::filesystem::path& filePath
)
{
    auto file = FileHandle::OpenInFile(filePath);
    GameState data;
    file >> data.playerNameOne;
    file >> data.playerScoreOne;
    file >> data.playerTimeOne;
    file >> data.playerAvatarOne;

    file >> data.playerNameTwo;
    file >> data.playerScoreTwo;
    file >> data.playerTimeTwo;
    file >> data.playerAvatarTwo;

    file >> data.gameMode;
    file >> data.aiDifficulty;
    file >> data.playerOneFirst;
    file >> data.gameTime;
    file >> data.gameEnd;

    if (file.fail()) {
        return std::nullopt;
    }

    short a, b;
    while (!file.eof()) {
        file >> a >> b;
        if (file.eof()) break;
        if (file.fail() && !file.eof()) {
            return std::nullopt;
        }
        data.moveList.emplace_back(a, b);
    }
    return data;
}
```

*Parameters:*
    - `filePath`: Đường dẫn của file lưu

*Return:*
    - Trạng thái của ván đấu được tải

=== Màn hình game chính
Trong tất cả các màn hình được cài đặt trong chương trình, màn hình game chính là màn hình có cấu trúc phức tạp nhất. Ngoài việc xử lý giao diện của các nước đi và các tính năng bổ trợ (cảnh báo nước 4, nháp, gợi ý) trên bàn cờ, còn phải chú tâm đến các thành phần khác như khung trạng thái (chứa thời gian, số trận thắng của người chơi), khung avatar và khung lịch sử nước đi. Ngoài ra, vì trong quá trình chơi, người chơi có thể tạm ngừng ván đấu, và tiếp tục ngay sau đó, nên việc lưu trữ trạng thái và hiển thị bàn cờ hiện tại cũng trở thành một vấn đề phải đề cập đến.

==== GameScreenView
Phần chương trình đảm nhiệm cho giao diện của màn hình game nằm trong view `GameScreenView`. Đoạn code nằm trong đây có thể được chia làm 3 phần:
  - Phần 1: khai báo các biến cần thiết, tiền xử lý và khởi động các thao tác trước khi bắt đầu vào vòng lặp chính.
  - Phần 2: vòng lặp chính, mọi sự tương tác của người chơi đều được xử lý trong đây.
  - Phần 3: xử lý các nghiệp vụ sau khi ván đấu kết thúc.
*Implementation:*
```Cpp
void GameScreenView::GameScreenView(NavigationHost& NavHost) {
    // Phần 1
    NavHost.SetContext(
        Constants::NEXT_VIEW, 
        Constants::NULL_VIEW
    );
    NavHost.SetContext(
        Constants::IS_SAVED,
        false
    );
    NavHost.SetContext(
        Constants::CURRENT_BGM, 
        Audio::Sound::GameBGM
    );
    /*...*/
    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, 
        std::vector<short>(Constants::BOARD_SIZE, 0)
    );
    /*...*/
    GameScreen gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);
    /*...*/

    // Phần 2
    while (!endGame) /* Vòng lặp chính */
    
    // Phần 3
    /*...*/
    curGameState.gameEnd = endGame;
    NavHost.SetContext(Constants::FINISHED_GAME, curGameState);
    return NavHost.Navigate("GameEndView");
}
```
Ngoài ra, mọi thao tác được xử dụng trong `GameScreenView` như xử lý nước đi của người chơi, thực hiện các tính năng bổ trợ, xử lý kết thúc ván đấu,... đều nằm trong `namespace GameScreenAction`. Việc tách ra như vậy sẽ giúp chương trình dễ dàng được kiểm soát hơn. Nếu gộp hết tất cả vào một nơi, thì phần code cho đoạn này sẽ dài hơn 1000 dòng.

*Interface:*
```Cpp
namespace GameScreenAction {
    // Cập nhật cả frontend và backend của ván đấu
    void UpdateGame(
        GameScreen gameScreen,
        GameAction::Board& board,
        short& moveCount,
        const GameAction::Point& move,
        const Constants::Player& player,
        GameState& gameState,
        bool loadFromSave = false
    );

    // Nổi bật con trỏ di chuyển
    void HighLightCursor(
        GameScreen& gameScreen,
        const GameAction::Board& gameBoard,
        const GameAction::Point& curPos,
        const ColorMatrix& colorMatrix,
        std::mutex& lock,
        bool isGhostMode
    );
    /*...*/
}
```

===== Class GameScreen
Giao diện của trò chơi được dựng nên và xử lý qua `class GameScreen`, và được cấu thành bởi 2 thành phần là: bàn cờ và các khung bổ trợ. Tương ứng, ta có `class BoardContainer` và `class Container`. 

===== Class Container
Đối với thành phần sau, các "container" đơn thuần là những khung hình chữ nhật được vẽ qua hàm `View::DrawRect` tại một tọa độ, với chiều dài và chiều rộng lúc khai báo, và có vai trò "chứa" những thông tin của bàn cờ. Để có thể điền vào những container này, ta gọi method `DrawToContainer`, với tham số là giá trị muốn được hiển thị. Ví dụ, container `timerContainerOne` sẽ hiển thị thời gian hiện tại của người chơi 1, còn container `winCountContainerOne` sẽ hiển thị số trận thắng của người chơi 1. Mỗi container thường chỉ hiển thị một giá trị nhất định, nhưng đối với `logContainer`, vì số lượng thông tin hiển thị nhiều và phức tạp hơn, ta cần một method riêng tên `DrawToLogContainer`.

*Interface:*
```Cpp
class Container {
    // Vẽ khung của container
    void DrawContainer();

    // Vẽ giá trị bên trong container
    void DrawToContainer(
        std::wstring value, 
        View::Color color = 
            Theme::GetColor(ThemeColor::TEXT_COLOR)
    );

    // Vẽ giá trị bên trong container lịch sử nước đi
    void DrawToLogContainer(
        const std::vector<std::pair<short, short>>& moveList,
        const std::wstring& playerNameOne,
        const std::wstring& playerNameTwo,
        bool playerOneFirst,
        short winMethod = 0,
        bool isReplay = false,
        short goBack = 0
    );
};
```

*Parameter*
- `value`: giá trị hiển thị trong container
- `color`: màu sắc vẽ giá trị
- `moveList`: danh sách nước đi hiện tại
- `playerNameOne`, `playerNameTwo`: tên người chơi 1, người chơi 2
- `playerOneFirst`: xác nhận lượt đầu tiên là của người chơi 1
- `winMethod`: kết quả ván đấu
- `isReplay`: xác nhận đang vẽ trong màn hình phát lại
- `goBack`: số lần cuộn lên của container

*Usage:*
```Cpp
{
    Container timerPlayerOne, logContainer;
    /*Thực hiện gán giá trị xCoord, yCoord,... cho container...*/

    // Vẽ thời gian người chơi 1
    timerPlayerOne.DrawToContainer(
        L"05:00", 
        Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR));

    // Vẽ danh sách các nước đi đã thực hiện
    logContainer.DrawToLogContainer(
        moveList, 
        L"Adam", 
        L"Bob", 
        true, 
        Constants::ENd_GAME_WIN_ONE);
}
```

===== Class BoardContainer
Tương tự như các container, bàn cờ cũng sẽ có hai phần là: vẽ giao diện của bàn cờ và hiển thị giá trị của quân cờ. Vì các quân cờ đều có những vị trí khác nhau, nên ta cần thực hiện phép tính để quân cờ hiện vào đúng vị trí tương ứng trên bàn cờ.

*Interface:*
```Cpp
class BoardContainer {
    // Vẽ giao diện bàn cờ
    void DrawBoardContainer();
    void DrawBoardRow();
    void DrawBoardCol();

    // Vẽ quân cờ vào ô cờ
    void DrawToBoardContainerCell(
        short row, 
        short col,
        std::wstring value, 
        View::Color color = View::Color::BLACK,
        bool highlight=false, 
        bool isGhostMode = false
    );
    // Vẽ các label theo chiều ngang bàn cờ
    void DrawBoardHorizontalLabels();
    // Vẽ các label theo chiều dọc bàn cờ
    void DrawBoardVerticalLabels();
};
```
==== Xử lý nước đi 
Mọi tương tác của người chơi đều sẽ được xử lý trong vòng lặp chính của `GameScreenView`. Cụ thể hơn, khi người chơi ấn một phím *lệnh* (phím di chuyển, phím chức năng, phím tạm ngừng,...) thì các thao tác tương ứng sẽ được thực hiện trong `GameScreenAction`. Đặc biệt, khi người chơi thực hiện nước đi (phím Enter), hàm `HandlePlayerMove` sẽ được gọi, đây là hàm xử lý nước đi của người chơi. Mỗi khi hàm trên được sử dụng, các hàm xử lý con như `HighLightMove`, `UnhighlightMove`, `FlipTurn` sẽ được kích hoạt để xử lý giao diện cho nước đi và logic của ván đấu. Nhưng quan trọng nhất là hai hàm con `UpdateGame` và `HandleState`:
- `UpdateGame`: đây là nơi duy nhất có quyền sử dụng đến hàm `MakeMove` được đề cập ở những mục trên. Hay nói cách khác, chỉ khi hàm này được gọi thì nước đi của người chơi mới được lưu lại trên bàn cờ. Ngoài ra, hàm cũng lưu nước đi đó vào danh sách nước đi hiện tại của bàn cờ, nhằm phục vụ việc lưu trữ sau này.
- `HandleState`: mỗi khi một nước đi được thưc hiện, hàm `HandleState` sẽ có vai trò kiểm tra nước đi đó có phải là nước đi kết thúc ván đấu hay không (nước đi thắng hoặc nước đi hòa). Nếu có, hàm sẽ thực hiện những thao tác kết thúc ván đấu, từ đó chuyển `GameScreenView` sang phần hậu xử lý.
Nếu không có hai hàm này, tuy vẫn có giao diện, trò chơi sẽ không thể hoạt động.

*Bên trong hàm HandleState*
```Cpp
{
    /*...*/ 
    // Lấy trạng thái ván đấu
    short state = Logic::GetGameState(
        board, moveCount, move, player.value, winPoint, true
    );
    switch (state) {
        // Xử lý các trạng thái tương ứng
        case Logic::WIN_VALUE:
            if (isPlayerOneTurn) {
                curGameState.playerScoreOne++;
                endGame = Constants::END_GAME_WIN_ONE;
            } else {
                curGameState.playerScoreTwo++;
                endGame = Constants::END_GAME_WIN_TWO;
            }
            HightLightWin(
                move, 
                winPoint, 
                player.symbol, 
                gameScreen
            );
            break;
        case Logic::DRAW_VALUE:
            endGame = Constants::END_GAME_DRAW;
            break;
    }
    /*...*/ 
}
```

*Bên trong hàm UpdateGame*
```Cpp
{
    // Thực hiện nước đi
    GameAction::MakeMove(board, moveCount, move, player.value);

    if (!loadFromSave) {
        // Lưu nước đi vào danh sách nước đi
        if (move.row != -1) {
            gameState.moveList.push_back({move.row, move.col});
        }
        gameScreen.logContainer.DrawToLogContainer(
            gameState.moveList,
            gameState.playerNameOne,
            gameState.playerNameTwo,
            gameState.playerOneFirst
        );
    }
}
```
==== Lưu và load trạng thái ván đấu
Trong quá trình chơi, sẽ có lúc người chơi tạm ngưng ván đấu, và quay lại một lúc sau đó. Khi ấy, màn hình game sẽ chuyển sang màn hình tạm ngưng, tức đã thoát khỏi scope của `GameScreenView`, và khi người chơi quay lại, một `GameScreenView` mới sẽ được tạo nên, với dữ liệu khác dữ liệu ván đấu đang diễn ra. Vì vậy, cần phải xử lý việc lưu trữ và load ván đấu hiện tại. Đối với việc lưu, ngay khi người chơi tạm ngưng, trạng thái ván đấu hiện tại sẽ được lưu qua đoạn code bên dưới:
```Cpp
// Tạm ngưng ván đấu
if (tmp == L"ESC") {
    // Lưu trạng thái ván đấu vào context tương ứng
    NavHost.SetContext(Constants::CURRENT_GAME, curGameState);
    // Chuyển sang màn hình tạm ngưng
    return NavHost.Navigate("PauseMenuView");
}
```
Từ đó, khi qua một `GameScreenView` mới, ta chỉ cần lấy trạng thái ván đấu qua context `Constants::CURRENT_GAME`
```Cpp
// Bên trong phần 1 của GameScreenView
{
    /*...*/
    GameState curGameState =
    std::any_cast<GameState>
    (NavHost.GetFromContext(Constants::CURRENT_GAME));
    /*...*/
}
```
Sau khi đã có trạng thái của ván đấu, việc tiếp theo là hiển thị các nước đi đã thực hiện lên bàn cờ, và cập nhật những biến cần thiết. Việc này được thực hiện trước khi vào vòng lặp chính của `GameScreenView`, qua hàm `LoadGameToView`
*Interface:*
```Cpp
void GameScreenAction::LoadGameToView(
    GameScreen& gameScreen,
    GameAction::Board& board,
    short& moveCount,
    GameState& gameState,
    AI& ai,
    std::vector<GameAction::Point>& warningPointList,
    ColorMatrix& colorMatrix,
    std::mutex& lock
);
```

*Parameters:*
- `gameScreen`: màn hình game.
- `board`: bàn cờ hiện tại.
- `moveCount`: số nước đi đã thực hiện.
- `gameState`: trạng trái ván đấu hiện tại.
- `ai`: AI sử dụng cho ván đấu.
- `warningPointList`: danh sách các nước cảnh báo 4.
- `colorMatrix`: bảng màu sắc của bàn cờ.
- `lock`: khóa mutex.

*Usage:*
```Cpp
{
    /* Sau khi có được trạng thái ván đấu, khai báo các biến cần thiết*/
    
    // Vẽ màn hình game
    gameScreen(7, 2);
    gameScreen.DrawGameScreen();
    gameScreen.DrawToElements(curGameState);

    // Load trạng thái game hiện tại vào các biến và màn hình game
    GameScreenAction::LoadGameToView(
        gameScreen,
        gameBoard,
        moveCount,
        curGameState,
        myAI,
        warningPointList,
        colorMatrix,
        lock
    );
    /*...*/
}
```

=== Các màn hình khác