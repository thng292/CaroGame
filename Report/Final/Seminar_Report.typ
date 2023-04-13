#set document(
    title: "Đồ án kĩ thuật lập trình nhóm 11",
    author: "Nhóm 11 - 22CLC01"
)

#import "style.typ": template

#show: template
 
#include "title.typ"

#align(center, heading(numbering: none)[Lời cảm ơn])
#pagebreak()

#heading(numbering: none)[Mục lục]
#outline(
    title: none,
    indent: true
)
#pagebreak()

#heading(numbering: none)[Danh sách hình]
#locate(loc => {
    let figures = query(figure, loc)
    let res = ()
    for index, fig in figures [
        #grid(
            columns: (auto, 1fr, auto),
            rows: (auto),
            [Hình #(index+1). ] + fig.caption,
            repeat[.],
            [#fig.location().page()]
        )
    ]
})
#pagebreak()

= Tổng quan về trò chơi

== Giới thiệu về trò chơi

=== Gomoku
Nguyên

=== Mục tiêu đề ra
    - Game có nhiều ngôn ngữ, người dùng có thể thêm được ngôn ngữ mới
    - Có thể load được các theme(chủ đề) bên ngoài
    - Lưu được các thiết lập của người chơi
    - Có thể save, load game đang chơi
    - Có thể lưu và phát lại các game đã hoàn thành
    - Có nhiều chế độ chơi
    - Có thể chơi với máy, máy có nhiều mức độ
    - Game có thể phát nhạc nền, hiệu ứng. Có thể bật tắt được

=== Thông tin chung về trò chơi
Nguyên
Link souce code, chạy trên nền tảng nào, ...

== Mô tả về các tính năng của game

=== Đa ngôn ngữ

=== Thay đổi Theme(Chủ đề)

=== Lưu thiết lập của người chơi

=== Save/Load game đang chơi, replay game đã chơi xong

=== Chế độ chơi Thường

=== Chế độ chơi Rush

=== Đánh với máy

=== Đánh với người

=== Các hỗ trợ trong lúc chơi game

==== Gợi ý

==== Nổi bật nước mới đi

==== Cảnh báo nước 4

==== Hoàn tác nước đi

==== Đi nháp


= Chi tiết các chức năng

== Logic

=== Chơi hiệu ứng, nhạc nền

Các file âm thanh được đặt trong thư mục asset/audio và có thể truy cập bằng các `enum`. Các `enum` được map sang một mảng chứa tên các file âm thanh. Các hàm và class nằm trong `namespace Audio`, file `Audio.h`, `Audio.cpp`

#grid(
    rows: (auto), 
    columns: (1fr, 1fr),
    gutter: 8pt,
```cpp
enum class Sound : char {
    NoSound = 0,
    OnKey,
    Draw,
    Win,    
    Lose,
    MenuBGM,
    MenuMove,
    MenuSelect,
    GameBGM,
    WinSound,
    GamePlace,
    GameStart,
    Pause,
    WarningSound
};
```,
```Cpp
constexpr std::array SoundName{
    L"",
    L"Key.wav",
    L"Draw.mp3",
    L"Win.mp3",
    L"Lose.mp3",
    L"MenuBGM.mp3",
    L"MenuMove.wav",
    L"MenuSelect.wav",
    L"GameBGM.mp3",
    L"WinSound.mp3",
    L"GamePlaceMove.mp3",
    L"GameStart.wav",
    L"Pause.wav",
    L"Warning.mp3"
};
```
)

==== Hàm PlayAndForget 
Hàm này sử dụng hàm PlaySound @PlaySound để chơi nhạc. Được dùng để chơi những âm thanh ngắn, dung lượng nhỏ dưới 100kb. Khi gọi hàm sẽ tự load file vào memory, chơi và đóng file. Do phải load cả file vào bộ nhớ nên khi chơi có độ delay cao và chỉ có thể mở được file `wav`. Được ứng dụng để chơi các âm thanh liên quan tới giao diện, các âm thanh không quan tâm tới độ trễ.

Interface:
```Cpp
    bool PlayAndForget(Sound sound, bool wait)
```

Parameters:
    - `Sound`: âm thanh cần chơi
    - `wait`:\ 
        - `true`  => phát âm thanh một cách đồng bộ (synchronous)\
        - `false` => phát âm thanh một cách bất đồng bộ (asynchronous)

Usage:
```Cpp
    Audio::PlayAndForget(Audio::Sound::MenuSelect);
```

==== Class AudioPlayer

Class này sử dụng #strong(`Media Control Interface`) (`MCI`) @MCI  để chơi nhạc nên giải quyết được các vấn đề của hàm `PlayAndForget`. Chơi được các file âm thanh định dạng `mp3` và `wav`, chơi được các file lớn, ít delay do không cần load hết file vào bộ nhớ. Nhược điểm là cần phải quan tâm đến tuổi thọ của class nên không tiện dụng như `PlayAndForget`. Được dùng để chơi nhạc nền, những đoạn nhạc cần độ trễ thấp hoặc file `mp3`.

Interface:
```
class AudioPlayer {
    // Ngăn copy hay move class
    AudioPlayer(AudioPlayer&&) = delete;
    AudioPlayer(const AudioPlayer&) = delete;
    AudioPlayer& operator=(AudioPlayer&&) = delete;
    AudioPlayer& operator=(const AudioPlayer&) = delete;

    AudioPlayer();
    AudioPlayer(Sound song); // Khởi tạo và mở file

    // Mở file. Có thể dùng để đổi file cần chơi
    int Open(Sound song);    
    Sound getCurrentSong() const;

    int Play(bool fromStart = 1, bool repeat = 0) const; // Chơi
    int Pause() const;      // Tạm dừng
    int Resume() const;     // Tiếp tục
    int Stop() const;       // Dừng chơi và trả con trỏ về đầu
    int Close();            // Đóng file đang mở

    ~AudioPlayer();         // Đóng file đang mở
}
```

Parameters:
    - `song`: âm thanh cần chơi
    - `fromStart`:\
        - `true`  => chơi từ đầu\
        - `false` => chơi tiếp tại vị trí con trỏ
    - `repeat`: \
        - `true` => lặp lại khi kết thúc

Return:
    - Các phương thức sẽ trả về `MCI code` của lệnh MCI tương ứng

Usage:
```
{
    Audio::AudioPlayer player(Audio::Sound::Draw);
    player.play(true, true);
    player.pause();
    player.resume();
    player.close();
}
```

==== Static class BackgroundAudioService

Class này được dùng để chơi nhạc nền, sử dụng class AudioPlayer để chơi nhạc vì có tuổi thọ dài.

Interface:
```
class BackgroundAudioService {
    BackgroundAudioService() = delete;
    static Audio::Sound GetCurrentSong();   

    static int ChangeSong(Audio::Sound song) // Đổi nhạc
    
    static int Play(bool fromStart = 0, bool repeat = 1); // Chơi
    static int Pause();                      // Tạm dừng
    static int Resume();                     // Tiếp tục
    // Dừng chơi, trả con trỏ về đầu
    static int Stop();
};
```

Parameters:
    - `song`: âm thanh cần chơi
    - `fromStart`:\
        - `true`  => chơi từ đầu\
        - `false` => chơi tiếp tại vị trí con trỏ
    - `repeat`: \
        - `true` => lặp lại khi kết thúc


Usage:
```
{    
    BackgroundAudioService::ChangeSong(Audio::Sound::MenuBGM);
    BackgroundAudioService::Play(true, true);
}
```

=== Điều hướng trong ứng dụng
Thông

=== Đồng hồ
Thông

=== Đọc, ghi, tìm file
Các hàm nằm trong `namespace FileHandle`, file `FileHandle.h`, `FileHandle.cpp`

==== Các hàm hỗ trợ mở file
Hỗ trợ mở các file văn bản `utf-8`

Interface:
```
    typedef std::filesystem::path fsPath;
    std::wofstream OpenOutFile(const fsPath& filePath);
    std::wifstream OpenInFile (const fsPath& filePath);  
```

Parameters:
    - `filePath`: đường dẫn đến file cần mở

Usage:
```
#include <string>
{
    std::wstring str = L"Tiếng Việt";
    auto outFile = FileHandle::OpenOutFile("test.txt");
    outFile <<  str;
    outFile.close();
    auto inFile  = FileHandle::OpenInFile ("test.txt");
    infile  >> str;
}
```

==== Hàm Ensure
Dùng để đảm bảo đường dẫn đến file muốn mở có tồn tại, nếu không tồn tại, nếu không tồn tại thì tạo đường dẫn đó.

Interface:
```
    void Ensure(const std::filesystem::path& Dir);
```

Parameters:
    - `Dir`: đường dẫn muốn kiểm tra/tạo

Return:
    - Các fstream tương ứng với thao tác In/Out

Usage:
```
{
    // Đảm bảo đường dẫn tương đối "asset/language" tồn tại
    FileHandle::Ensure("asset/language"); 
}
```

==== Hàm Delete
Dùng để xóa file

Interface:
```
    bool Delete(const std::filesystem::path& target)
```

Paramterers:
    - target: đường dẫn tới file cần xóa

Return:
    - Trả về `true` nếu xóa thành công, `false` khi lỗi

Usage:
```
{
    // Xóa file tmp.cpp
    bool res = FileHandle::Delete("tmp.cpp");
    if (res) {
        std::cout << "Success";
    } else {
        std::cout << "Failed";
    }
}
```

==== Hàm GetAllTextFileInDir
Tìm các file văn bản thuần trong thư mục

Interface:
```
struct FileDetail {
    std::filesystem::path               filePath;
    std::filesystem::file_time_type     lastModified;
};

std::vector<FileHandle::FileDetail> 
FileHandle::GetAllTextFileInDir(
    const std::filesystem::path& Dir
);
```

Parameters:
    - `Dir`: đường dẫn đến thư mục muốn tìm

Return:
    - Trả về một `vector` chứa các thông tin của các file đã tìm được

Usage:
```
{
    // Tìm các file văn bản trong đường dẫn
    // tương đối "asset/language"
    auto files = FileHandle::GetAllTextFileInDir(
        "asset/language"
    );
    for (auto& file:files) {
        std::cout << file.filePath.filename() << '\n';
    }
}
```

=== Ngôn ngữ
Các văn bản trong trò chơi sẽ được load từ một file riêng, điều này kiến cho phần ngôn ngữ trong game dễ tùy biến và thêm các ngôn ngữ mới.

File ngôn ngữ là một file văn bản thuần chứa các nhãn và phần văn bản ngăn cách bởi dấu "=", các nhãn có nằm bên trong cặp ngoặc `[]` là `meta` được dùng để chứa thông tin về file ngôn ngữ

Ví dụ file ngôn ngữ:
```text
[LANGUAGE]                  =    English
[LANG_SELECT]               =    Language
ABOUT_DESC                  =    LIST OF GROUP MEMBERS AND SOURCE CODE LINK
ABOUT_SHORTCUT              =    A
ABOUT_TITLE                 =    About us
ABOUT_US_TITLE              =    About us
```

Các phần văn bản sẽ được truy xuất thông qua nhãn tương ứng.
Các phần liên quan tới ngôn ngữ nằm trong file `Language.h` và `Language.cpp`

==== Static class Language
Hàm chứa các phương thức và các văn bản ngôn ngữ

Interface:
```
typedef std::unordered_map<std::wstring, std::wstring> Dict;
typedef std::filesystem::path fsPath;

struct LanguageOption {
  Dict meta;
  fsPath path;
};

class Language {
  static Dict languageDict;

public:
  Language() = delete;

  // Chỉ đọc các phần thông tin về ngôn ngữ
  static Dict ExtractMetaFromFile(const fsPath& filePath);

  // Load file ngôn ngữ
  static void LoadLanguageFromFile(const fsPath& filePath);

  // Tìm các file ngôn ngữ
  static std::vector<LanguageOption> 
  DiscoverLanguageFile(const fsPath& dirPath);

  // Truy xuất văn bản bằng nhãn
  static const std::wstring& 
  GetString(const std::wstring& Label);

  static const std::wstring& 
  GetMeta(const std::wstring& Label);
};
```

Parameters:
    - `filePath`: đường dẫn tới file cần mở
    - `dirPath`: đường dẫn tới thư mục cần tìm
    - `Label`: nhãn của văn bản cần lấy

Usage:
```
{
    Language::LoadLanguageFromFile("asset/language/en.txt");
    std::cout << Language::GetMeta(L"[LANGUAGE]");
    std::cout << Language::GetMeta(L"ABOUT_TITLE");
}
```

=== Cài đặt
Thông

=== Chủ đề
Thông

=== Hàm trung gian hỗ trợ vẽ giao diện
Thông

=== Nhận biết thắng thua
Việc nhận biết kết quả thắng, thua, và hòa của một ván đấu được thực hiện trong ```Cpp namespace Logic``` của chương trình. Các kết quả này là điều kiện để chương trình quyết định kết thúc ván đấu. Ngoài ra, việc biết được kết quả thắng, thua, và hòa sẽ giúp AI của trò chơi đưa ra đánh giá về trạng thái bàn cờ một cách đúng đắn.

==== Hàm GetGameState
Hàm `GetGameState` có vai trò đánh giá hiện trạng của ván đấu sau nước đi mới nhất. Cụ thể hơn, hàm xem xét nước đi mới nhất có dẫn đến một *kết quả thắng* hay *kết quả hòa*. Một nước đi sẽ dẫn đến kết quả thắng nếu nước đi đó tạo nên một chuỗi 5 nước đi liên tiếp đồng chất, và một nước đi sẽ dẫn đến kết quả hòa nếu nước đi đó không phải là nước đi thắng, đồng thời là nước đi hợp lệ cuối cùng của bàn đấu. 

Interface:
```Cpp
    short GetGameState(
        const GameAction::Board& board,
        const short& moveCount,
        const GameAction::Point& move,
        const short& playerValue,
        GameAction::Point& winPoint = temp,
        bool getWinPoint
    );
```
Parameters:
    - `board`: Bàn đấu hiện tại.
    - `moveCount`: Số nước đi đã thực hiện. 
    - `move`: Nước đi mới nhất.
    - `playerValue`: Người chơi thực hiện nước đi.
    - `winPoint`: Đầu mút của chuỗi thắng (nếu có).
    - `getWinPoint`:
        - `true` => lấy đầu mút của chuỗi thắng (nếu có).
        - `false` => không lấy đầu mút của chuỗi thắng.

Returns:
    - ```Cpp Logic::WIN_VALUE```: Giá trị tượng trưng kết quả thắng.
    - ```Cpp Logic::DRAW_VALUE```: Giá trị tượng trưng kết quả hòa.
    - ```Cpp Logic::NULL_VALUE```: Giá trị tượng trưng kết quả vô định.

Usage:
```Cpp
short gameState = Logic::GetGameState(gameBoard, moveCount, latestMove, currentPlayer, winPoint, true);
```

=== Các tương tác với bàn cờ
Trạng thái bàn cờ có thể được thay đổi qua hai hình thức: *thực hiện nước đi* và *xóa nước đi*. Hàm `MakeMove` và `UndoMove` đảm nhiệm việc thực hiện hai chức năng ấy. Hai hàm này tuy đơn giản nhưng nắm vai trò quan trọng xuyên suốt quá trình chơi, vì các thao tác người chơi chỉ thực sự được ghi lại trên bàn cờ khi hai hàm này được gọi đến. Việc xóa nước đi là để phục vụ cho chức năng `Hoàn tác` của trò chơi, và là một phần không thể thiếu đối với thuật toán `Minimax` được sử dụng cho AI của trò chơi.


Interface:
 ```
 // Thực hiện nước đi lên bàn cờ
 void MakeMove(
    Board& board,
    short& moveCount,
    const Point& move,
    const short& playerValue
);

// Xóa nước đi khỏi bàn cờ
void UndoMove(
    Board& board, 
    short& moveCount, 
    const Point& move
);
 ```
Parameters:
    - `board`: Bàn đấu hiện tại.
    - `moveCount`: Số nước đi đã thực hiện. 
    - `move`: Nước đi được thực hiện.
    - `playerValue`: Người chơi thực hiện nước đi.

Usage:
```Cpp
GameAction::MakeMove(board, moveCount, latestMove, currentPlayer);
GameAction::UndoMove(board, moveCount, latestMove, currentPlayer);
```

=== AI
Việc thiết kết chương trình cho chế độ `Đánh với máy` là một trong những thách thức lớn nhất của đồ án. Khác với những tính năng khác của chương trình, tính năng này đòi hỏi những mảng kiến thức chuyên biệt về các thuật toán, kĩ thuật lập trình cụ thể. Ngoài ra, việc đánh giá độ đúng/sai của chương trình, hay nói cách khác là nước đi máy tính tìm được là tốt hay xấu, sẽ phần lớn phụ thuộc vào cảm tính và sự hiểu biết của người viết. Chính vì vậy, chương trình có thể đánh hay đối với người này, nhưng đánh không tốt đối với người khác. Phần tiếp theo sẽ trình bày những kĩ thuật mà nhóm đã sử dụng cho chương tình AI.

==== Thuật toán Minimax

==== Đánh giá bàn cờ

==== Cải thiện tốc độ

===== Alpha-Beta pruning

===== Sắp xếp nước đi tìm kiếm

===== Transposition table (Bảng hoán vị)

===== So sánh tốc độ

==== Phân độ khó

==== Chức năng "Gợi ý"

==== Những mặt cần cải thiện

== Giao diện

=== Cài đặt
Thông

=== Các màn hình lưu, tải game và replay
Thông

=== Màn hình trò chơi chính
Vũ

=== Các màn hình khác

= Đánh giá thành viên

= Kết luận

== Kết quả đạt được

=== Ưu điểm của trò chơi

    - Có thể thêm nhiều ngôn ngữ và theme vào trò chơi
    - Có nhạc hay, hiệu ứng sống động
    - Có chế độ tính thời gian
    - AI chạy tương đối tốt, đánh nhanh
    - Lối chơi đa dạng
    - Có nhiều nhân vật ngộ nghĩnh
    - Có nhiều tính năng hỗ trợ khi chơi game
    - Có thể xem lại trận đấu đã chơi
    - Màn hình save/load có khả năng tương tác tốt
    - Hướng dẫn dễ hiểu, có gợi ý ở mỗi màn hình

=== Khuyết điểm của trò chơi
    -

== Các khó khăn gặp phải
    - Một vài thành viên không có kinh nghiệm sử dụng git và GitHub
    - Khó khăn khi lập trình đa luồng do không có kinh nghiệm
    - Màn hình terminal vẽ các kí tự chậm


== Những gì đã học được
    - Cách làm việc nhóm với git và GitHub
    - Cách sử dụng các tính năng mới của C++ 20
    - Cách sử dụng các tính năng liên quan tới đo hiệu năng, format code và debug trong Visual Studio
    - Cách làm việc nhóm hiệu quả
    - Cách lên kế hoạch, phân chia công việc
    - Cách lập trình hướng đối tượng cơ bản
    

== Các kinh nghiệm rút ra
    - Khi code, nên tách nhỏ các hàm ra, không nên viết hàm dài
    - Code xong một hàm phải kiểm tra kĩ, tránh phát sinh lỗi về sau
    - Không nên viết code mà không thiết kế trước
    - Nên viết code theo một quy chuẩn nhất định và đồng bộ trong 1 dự án
    - Nên viết code có tính tái sử dụng cao
    - Cần có kế hoạch và phân chia công việc rõ ràng
    - Code xong phải có người review lại

== Lí do hoàn thành mục tiêu
Nguyên

== Hướng phát triển ứng dụng
    - Có thể chơi 2 người qua mạng lan
    - Thêm nhiều ngôn ngữ mới
    - Thêm nhiều chủ đề hơn
    - Hiện lợi thế của 2 bên
    - Đưa game lên nhiều nền tảng khác

#bibliography(title: "Tài liệu tham khảo", "ReportBib.yml")
