#set document(
    title: "Đồ án kĩ thuật lập trình nhóm 11",
    author: "Nhóm 11 - 22CLC01"
)

#import "style.typ": template, figureOutline
#show: template
 
#include "title.typ"

#align(center, heading(numbering: none)[Lời cảm ơn])
#pagebreak()

#heading(numbering: none)[Mục lục]
#outline()
#pagebreak()

#heading(numbering: none)[Danh sách hình]
#figureOutline()

#include "readme.typ"

= Tổng quan về trò chơi

== Giới thiệu về trò chơi

=== Gomoku
Nguyên

=== Các yêu cầu về tính năng
    - Có thể save, load trò chơi
    - Nhận biết được thắng, thua, hòa
    - Xử lí hiệu ứng thắng, thua, hòa
    - Xử lí giao diện màn hình khi chơi
    - Xử lí màn hình chính
    - Game có nhiều ngôn ngữ, người dùng có thể thêm được ngôn ngữ mới
    - Có thể load được các theme(chủ đề) bên ngoài
    - Lưu được các thiết lập của người chơi
    - Có thể lưu và phát lại các game đã hoàn thành
    - Có nhiều chế độ chơi
    - Có thể chơi với máy, máy có nhiều mức độ
    - Game có thể phát nhạc nền, hiệu ứng. Có thể bật tắt được

=== Thông tin chung về trò chơi
Nguyên
Link souce code, chạy trên nền tảng nào, ...

== Mô tả về các tính năng của game

=== Màn hình chính

=== Save/Load game đang chơi, replay game đã chơi xong

=== Xử lí, hiệu ứng thắng, thua, hòa

=== Giao diện màn hình khi chơi

=== Đa ngôn ngữ

=== Thay đổi Theme(Chủ đề)

=== Lưu thiết lập của người chơi

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

Âm thanh là một phần không thể thiếu trong các trò chơi điện tử, nó khiến cho trò chơi thêm sinh động và chân thực, nâng cao trải ngiệm thi chơi. Dưới đây là những phương pháp mà chúng em đã áp dụng để chơi âm thanh và những khó khăn mà chúng em đã gặp phải.

Các file âm thanh được đặt trong thư mục asset/audio và có thể truy cập bằng các `enum`. Các `enum` được map sang một mảng chứa tên các file âm thanh. Các hàm và class sau đây nằm trong `namespace Audio`, file `Audio.h`, `Audio.cpp`

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

==== Giải pháp để chơi các âm thanh của giao diện 

Để chơi các âm thanh của giao diện, giải pháp của chúng em là sử dụng hàm `PlaySound` @PlaySound. Hàm này có thể chơi các tài nguyên âm thanh thông qua tên file, con trỏ đến tài nguyên âm thanh trong bộ nhớ hoặc chơi âm thanh của một sự kiện hệ thống

Interface:
```
BOOL PlaySound(
    LPCTSTR pszSound,
    HMODULE hmod,
    DWORD   fdwSound
);
```
Parameter:
    - `pszSound`: Con trỏ đến tên file âm thanh, tài nguyên âm thanh trong bộ nhớ hoặc tên sự kiện hệ thống
    - `hmod`: Handle của chương trình chứa tài nguyên âm thanh, nếu chơi bằng tài nguyên âm thanh trong bộ nhớ
    - `fdwSound`: Các flag để chỉ định cách chơi âm thanh

*Return:*
    - `true`  #sym.arrow.r.double phát âm thanh thành công
    - `false` #sym.arrow.r.double phát âm thanh thất bại

Ví dụ sử dụng hàm `PlaySound`:
```
    // Chơi âm thanh từ file "recycle.wav"
    PlaySound(TEXT("recycle.wav"), NULL, SND_FILENAME);
    // Chơi âm thanh của 1 sự kiện hệ thống
    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
```

Ưu điểm:
    - Khi gọi hàm sẽ tự load file vào memory, đọc và phát
    - Sau khi gọi xong thì không cần quan tâm đến nữa nên có độ linh hoạt cao

Nhược điểm:
    - Phải load cả file vào bộ nhớ khi chơi nên chỉ chơi những âm thanh ngắn, dung lượng nhỏ, vừa memory
    - Khi chơi có độ delay cao (có thể đươc khắc phục bằng cách load trước file cần chơi)
    - Chỉ có thể mở được file có định dạng `wav`.
    - Không thể chơi cùng lúc nhiều âm thanh

Vì những âm thanh giao diện là những file ngắn, nhỏ, nên khắc phục được những điểm yếu của hàm và tận dụng tốt sự linh hoạt cao của hàm `PlaySound`. Nên chúng em đã chọn giải pháp này.

Để thuận tiện hơn trong việc sử dụng, chúng em đã viết hàm `PlayAndForget`.

Interface:
```Cpp
    bool PlayAndForget(Sound sound, bool wait)
```

*Parameters:*
    - `Sound`: âm thanh cần chơi
    - `wait`:\ 
        - `true`  #sym.arrow.r.double phát âm thanh một cách đồng bộ (synchronous)\
        - `false` #sym.arrow.r.double phát âm thanh một cách bất đồng bộ (asynchronous)

*Return:*
    - `true`  #sym.arrow.r.double phát âm thanh thành công
    - `false` #sym.arrow.r.double phát âm thanh thất bại

*Usage:*
```Cpp
    // Chơi âm thanh "MenuSelect.wav" bất đồng bộ
    Audio::PlayAndForget(Audio::Sound::MenuSelect);
```

==== Giải pháp để chơi nhạc nền

Với những nhược điểm trên thì hàm `PlaySound` không phù hợp để chơi những file dung lượng lớn như nhạc nền và những âm thanh yêu cầu độ trễ thấp. Vì vậy chúng em đã sử dụng một giải pháp khác là sử dụng `Media Control Interface` @MCI.
Media Control Interface là một chuẩn giao tiếp giữa các ứng dụng và các thiết bị âm thanh, video, hình ảnh, v.v... Nó cho phép các ứng dụng giao tiếp với các thiết bị âm thanh, video, hình ảnh thông qua chuỗi lệnh đơn giản.

Để gửi lệnh đến thiết bị âm thanh, chúng em sử dụng hàm `mciSendString` @mciSendString. Hàm này có thể gửi chuỗi lệnh đến thiết bị âm thanh và nhận kết quả trả về.

Interface:
```
    MCIERROR mciSendString(
        LPCTSTR lpszCommand,
        LPTSTR  lpszReturnString,
        UINT    cchReturn,
        HANDLE  hwndCallback
    );
```

*Parameters:*
    - `lpszCommand`: Con trỏ đến chuỗi lệnh cần gửi đến thiết bị âm thanh
    - `lpszReturnString`: Con trỏ đến mảng chứa chuỗi nhận thông tin trả về
    - `cchReturn`: Độ dài của chuỗi trả về
    - `hwndCallback`: Handle của cửa sổ sẽ nhận thông báo khi thiết bị âm thanh hoàn thành công việc

*Return:*
    - Nếu gửi thành công sẽ trả về `0`, nếu lỗi trả về một giá trị biểu thị lỗi 

*Usage:*
```
    // Mở file "song.mp3"
    mciSendString("open song.mp3 type mpegvideo alias song", NULL, 0, NULL);
    // Chơi file "song.mp3"
    mciSendString("play song from 0 repeat", NULL, 0, NULL);
    // Dừng file "song.mp3"
    mciSendString("stop song", NULL, 0, NULL);
    // Đóng file "song.mp3"
    mciSendString("close song", NULL, 0, NULL);
```

Ưu điểm:
    - Chơi được nhiều định dạng âm thanh khác nhau
    - Chơi được các file lớn
    - Khi chơi ít bị delay do không cần load hết file vào memory
    - Có thể chơi cùng lúc nhiều âm thanh
Nhược điểm:
    - Phải sử dụng chuỗi để giao tiếp 
    - Phải tự quản lí các file âm thanh đã mở nên không có độ linh hoạt cao

Để khắc phục nhược điểm trên, chúng em đã tạo `class AudioPlayer` để việc sử dụng và quản lí tài nguyên thuận tiện, dễ dàng hơn

Interface:
```
class AudioPlayer {
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

*Parameters:*
    - `song`: âm thanh cần chơi
    - `fromStart`:\
        - `true`  #sym.arrow.r.double chơi từ đầu\
        - `false` #sym.arrow.r.double chơi tiếp tại vị trí con trỏ
    - `repeat`: \
        - `true` #sym.arrow.r.double lặp lại khi kết thúc

*Return:*
    - Các phương thức sẽ trả về `MCI code` của lệnh MCI tương ứng

*Usage:*
```
{
    Audio::AudioPlayer player(Audio::Sound::Draw);
    player.play(true, true);
}
```

`class AudioPlayer` có một nhược điểm lớn là tuổi thọ phụ thuộc vào thời gian sống của biến cục bộ và không thể được truy cập được từ các thành phần bên ngoài. Để khắc phục điểm yếu ấy chúng em đã tạo ra `class BackgroundAudioService` để tăng tuổi thọ của `class AudioPlayer`, đồng thời khiến cho nhạc nền có thể được điều khiển những nơi khác.

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

*Parameters:*
    - `song`: âm thanh cần chơi
    - `fromStart`:\
        - `true`  #sym.arrow.r.double chơi từ đầu\
        - `false` #sym.arrow.r.double chơi tiếp tại vị trí con trỏ
    - `repeat`: \
        - `true` #sym.arrow.r.double lặp lại khi kết thúc


*Usage:*
```
{    
    BackgroundAudioService::ChangeSong(Audio::Sound::MenuBGM);
    BackgroundAudioService::Play(true, true);
}
```

=== Điều hướng trong ứng dụng

Việc chuyển đổi giữa các màn hình khác nhau trong trò chơi là một thách thức lớn đối với chúng em, vì đây là lần đầu chúng em gặp phải vấn đề này. Để giải quyết vấn đề này, ban đầu chúng em gọi các hàm trực tiếp từ main, muốn chuyển tới màn hình nào thì gọi hàm của màn hình đó. Nhưng phương pháp này nhanh chóng để lộ nhiều điểm yếu:
    - Cần phải biết chữ kí hàm của màn hình cần chuyển đến
    - Khó quản lí các màn hình và các đích đến của chúng
    - Có thể bị tràn stack khi chuyển màn hình nhiều lần
    - Nếu muốn sửa lại code phải sửa ở nhiều nơi
    - Khó mở rộng, dễ lỗi

Để khắc phục điểm yếu đó, chúng em đã tạo ra một hệ thống để quản lí các màn hình, lấy ý tưởng từ thư viện `navigation-compose` @ComposeNavigation (thư viện điều hướng của Jetpack @Jetpack). Hệ thống này giúp chúng em có thể chuyển đổi giữa các màn hình một cách dễ dàng, linh hoạt và có thể mở rộng dễ dàng hơn.

Hệ thống này gồm 2 thanh phần:
    - `class NavigationHost`: class trung tâm để quản lí các màn hình
    - Các màn hình: là các hàm có chữ kí như sau:
        - `void ScreenName(NavigationHost& host)`
        
Mỗi màn hình sẽ được gán một nhãn độc nhất, nhãn này sẽ được sử dụng để chuyển đến màn hình đó. Các màn hình muốn chuyển đến màn hình khác sẽ gọi phương thức `Navigate("Nhãn")` để chuyển đến màn hình đó hoặc `NavigateStack("Nhãn")` để chuyển đến màn hình đó nhưng không xóa đi màn hình hiện tại.
Ngoài ra, hệ thống còn có xử lí việc xóa màn hình trước khi chuyển đến màn hình mới, lưu lịch sử di chuyển giữa các màn hình để có thể quay lại màn hình trước đó và cung cấp một số phương thức để hỗ trợ việc truyền dữ liệu giữa các màn hình.

Interface:
```
#define ViewFunc std::function<void(NavigationHost&)>
#define ViewFuncMap std::unordered_map<std::string, ViewFunc>

class NavigationHost {

    NavigationHost() = default;
    NavigationHost(
        const std::string& Start, 
        const ViewFuncMap& links
    );

    // Các phương thức hỗ trợ truyền dữ liệu giữa các màn hình
    std::any& GetFromContext(const std::string& name);
    bool CheckContext(const std::string& name);
    void SetContext(
        const std::string& name, 
        const std::any& data
    );
    void DeleteContext(const std::string& name);

    // Thêm màn hình khi đang chạy
    void Add(const std::string& path, const ViewFunc& view);

    // Các phương thức hỗ trợ điều hướng
    void NavigateStack(const std::string& path);
    void Navigate(const std::string& path);
    void Back();
    void BackToLastNotOverlay();
    void NavigateExit();

    ~NavigationHost();
};
```

*Parameters:*
    - `Start`: nhãn của màn hình bắt đầu
    - `links`: danh sách các màn hình có trong ứng dụng và nhãn của chúng
    - `path`: nhãn của màn hình cần chuyển đến
    - `view`: hàm của màn hình cần chuyển đến
    - `name`: nhãn của dữ liệu cần truyền
    - `data`: dữ liệu cần truyền

*Usage:*
```
#include <iostream>

void GameScreen(NavigationHost& NavHost) {
    // Lấy dữ liệu đã truyền
    int a = std::any_cast<int>(NavHost.GetFromContext("Context"));
    std::cout << a;
    // ...
    // Thoát chương trình
    return NavHost.NavigateExit();
}

void StartScreen(NavigationHost& NavHost) {
    // Truyền dữ liệu giữa các màn hình
    NavHost.SetContext("Context", 90);
    // ...
    return NavHost.Navigate("Game");
}

int main() {
    // Khởi tạo hệ thống điều hướng
    NavigationHost(
        "Start", 
        {
            {"Start", StartScreen},
            {"Game", GameScreen},
        }
    );
    return 0;
}
```

Ưu điểm:
    - Dễ mở rộng
    - Không cần phải biết tên hàm để chuyển màn hình
    - Khi thay đổi chỉ cần sửa ở một nơi
Nhược điểm:
    - Khó chuyển dữ liệu giữa các màn hình
    - Dễ đánh sai nhãn màn hình


=== Phương pháp lưu và tải game(save/load game)

Để lưu game, chúng em đã chọn lưu trạng thái của game vào một file văn bản thuần và lưu trong một thư mục riêng. Để tải game, chúng em sẽ đọc file văn bản đó và khởi tạo lại trạng thái của game. 
Khi người dùng muốn tải game, chúng em muốn hiển thị một danh sách các file lưu game để người dùng có thể chọn file cần tải. Có nhiều phương pháp để thực hiện việc này. Một trong những giải pháp mà chúng em đã cân nhắc là lưu tên file lưu game vào một file văn bản thuần, khi cần tải, chúng em sẽ đọc file đó và hiển thị cho người dùng. Tuy nhiên, chúng em đã quyết định không sử dụng phương pháp này do nó có nhiều khuyết điểm như:
    - Tạo ra một file không cần thiết
    - Người dùng không thể tải game nếu file đó bị xóa/lỗi
    - Người dùng không thể load các file copy từ máy khác

Một cách tiếp cận khác là mỗi khi người dùng muốn tải game thì sẽ duyệt qua các file trong thư mục lưu game và hiển thị cho người dùng. Điều này có nhiều ưu điểm như:
    - Không cần tạo ra file không cần thiết
    - Người dùng có thể tải game từ máy khác

Để quét các file trong thư mục, chúng em đã sử dụng thư viện `filesystem` @filesystem. Đây là một thư viện mới xuất hiện trong phiên bản C++17. Nó cung cấp các tiện ích để thực hiện các thao tác trên hệ thống tập tin và các thành phần của chúng, chẳng hạn như đường dẫn, tập tin thông thường và thư mục. Để việc sử dụng thư viện thuận tiện hơn, chúng em đã viết hàm `GetAllTextFileInDir`.

*Implementation:*
```
namespace FileHandle {
struct FileDetail {
    std::filesystem::path               filePath;
    std::filesystem::file_time_type     lastModified;
};

std::vector<FileHandle::FileDetail> 
GetAllTextFileInDir(
    const std::filesystem::path& Dir
)
{
    std::vector<FileDetail> res;
    Ensure(Dir);
    for (auto& file : std::filesystem::directory_iterator(Dir)) {
        if (file.is_regular_file()) {
            res.emplace_back(
                file.path(), 
                file.last_write_time()
            );
        }
    }
    return res;
}
} // namespace FileHandle
```
_*Note:*_ Chi tiết về hàm `Ensure` nằm ở @EnsureFunc

*Parameters:*
    - `Dir`: đường dẫn đến thư mục muốn tìm

*Return:*
    - Trả về một `vector` chứa các thông tin của các file đã tìm được

*Usage:*
```
{
    // Tìm các file văn bản trong đường dẫn
    // tương đối "saves"
    auto files = FileHandle::GetAllTextFileInDir(
        "saves"
    );
    for (auto& file:files) {
        std::cout << file.filePath.filename() << '\n';
    }
}
```

==== Các hàm hỗ trợ khác
Các hàm sau nằm trong `namespace FileHandle`, file `FileHandle.h`, `FileHandle.cpp`

===== Các hàm hỗ trợ mở file
Hỗ trợ mở các file văn bản `utf-8`

Interface:
```
    typedef std::filesystem::path fsPath;
    std::wofstream OpenOutFile(const fsPath& filePath);
    std::wifstream OpenInFile (const fsPath& filePath);  
```

*Parameters:*
    - `filePath`: đường dẫn đến file cần mở

*Usage:*
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

===== Hàm Ensure <EnsureFunc>
Dùng để đảm bảo đường dẫn đến file muốn mở có tồn tại, nếu không tồn tại, nếu không tồn tại thì tạo đường dẫn đó.

Interface:
```
    void Ensure(const std::filesystem::path& Dir);
```

*Parameters:*
    - `Dir`: đường dẫn muốn kiểm tra/tạo

*Return:*
    - Các fstream tương ứng với thao tác In/Out

*Usage:*
```
{
    // Đảm bảo đường dẫn tương đối "asset/language" tồn tại
    FileHandle::Ensure("asset/language"); 
}
```

===== Hàm Delete
Dùng để xóa file

Interface:
```
    bool Delete(const std::filesystem::path& target)
```

*Parameters:*
    - target: đường dẫn tới file cần xóa

*Return:*
    - Trả về `true` nếu xóa thành công, `false` khi lỗi

*Usage:*
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

=== Đếm giờ trong khi chơi game

Việc đếm và hiển thị thời gian trực tiếp trong lúc chơi khá phức tạp vì luồng chính trong game luôn phải chời đợi và xử lí đầu vào của người dùng, nên việc sử dụng luồng chính để  nó phụ thuộc vào việc người chơi có thực hiện các thao tác trong game hay không. Nếu người chơi không thực hiện các thao tác trong game thì thời gian sẽ không được cập nhật lên màn hình. Để giải quyết vấn đề này, chúng em đã tạo thêm một luồng riêng để đếm thời gian và cập nhật lên màn hình. Sử dụng thư viện `thread` @thread để tạo luồng mới, chúng em đã có giải pháp để chạy một hàm sau một khoảng thời gian nhất định.

*Implementation:*
```
using namespace std::chrono;

struct TimerInternalState {
    std::function<void(void)> callback;
    milliseconds interval;
    bool running = false;
    bool pause = false;
};

class Timer {
    std::thread _thread;
    std::shared_ptr<TimerInternalState> _state { 
        new TimerInternalState };

   public:
    Timer(
        std::function<void(void)> callback, 
        const long& interval = 1000
    ) {
        _state->callback = callback;
        _state->interval = milliseconds{interval};
    }

    inline void Start()
    {
        _state->running = true;
        auto state = _state;
        _thread = std::thread([state] {
            while (state->running) {
                auto nextInterval = steady_clock::now();
                nextInterval += state->interval;
                if (!state->pause) { state->callback(); }
                std::this_thread::sleep_until(nextInterval);
            }
        });
        _thread.detach();
    }

    inline void Pause() { _state->pause = true; }
    inline void Continue() { _state->pause = false; }
    inline void Stop() { _state->running = false; }
    inline ~Timer() { Stop(); }
};
```

*Parameters:*
    - `callback`: hàm sẽ được gọi sau mỗi khoảng thời gian `interval`
    - `interval`: khoảng thời gian giữa các lần gọi hàm `callback` tính bằng mili giây

Việc lập trình đa luồng trong C++ khá phức tạp, và cũng là phần dễ gây lỗi nhất trong trò chơi, do việc vẽ lên màn hình phải được đồng bộ giữa các luồng với nhau. Nếu không đồng bộ thì có thể dẫn đến việc các phần tử trên màn hình bị vẽ sai vị trí. Để việc đó không xảy ra, chúng em đã sử dụng một khóa `mutex` @mutex chung để đồng bộ các luồng với nhau.

Đoạn code sử dụng `Timer` và `mutex` trích từ trò chơi:
```
void GameScreenView::GameScreenView(NavigationHost& NavHost) {
// ...
std::mutex lock;
// ...
Timer timerPlayerOne(
    [&] {
        if (!endGame) {
            curGameState.playerTimeOne += timeAddition;
            std::lock_guard guard(lock);
            auto currPos = View::GetCursorPos();
            // Vẽ thời gian lên màn hình
            gameScreen.timerContainerOne.DrawToContainer(
                Utils::SecondToMMSS(curGameState.playerTimeOne),
                Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR)
            );
            View::Goto(currPos.X, currPos.Y);
            if (curGameState.playerTimeOne == 0 && !endGame) {
                // Xử lí khi hết thời gian
            }
        }
    }
);
}
```



=== Giải pháp cho đa ngôn ngữ
Các văn bản trong trò chơi thay vì được code cứng vào trò chơi thì sẽ được load từ một file riêng, điều này kiến cho phần ngôn ngữ trong game có thể được chỉnh sửa một cách dễ dàng và khiến cho việc thêm các ngôn ngữ mới dễ dàng hơn.

File ngôn ngữ là một file văn bản thuần chứa các nhãn và phần văn bản ngăn cách bởi dấu "=", các nhãn có nằm bên trong cặp ngoặc `[]` là `meta` được dùng để chứa thông tin về file ngôn ngữ. Sau khi load xong, các nhãn và văn bản sẽ được lưu vào một bảng để có thể dễ dàng truy xuất.

Ví dụ file ngôn ngữ:
```text
[LANGUAGE]                  =    English
[LANG_SELECT]               =    Language
ABOUT_DESC                  =    LIST OF GROUP MEMBERS AND SOURCE CODE LINK
ABOUT_SHORTCUT              =    A
ABOUT_TITLE                 =    About us
ABOUT_US_TITLE              =    About us
```

Các nhãn và văn bản trong trò chơi được quản lí, truy xuất và load thông qua class `Language` nằm trong file `Language.h` và `Language.cpp`

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

*Parameters:*
    - `filePath`: đường dẫn tới file cần mở
    - `dirPath`: đường dẫn tới thư mục cần tìm
    - `Label`: nhãn của văn bản cần lấy

*Usage:*
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
Việc nhận biết kết quả thắng, thua, và hòa của một ván đấu được thực hiện trong `Cpp namespace Logic` của chương trình. Các kết quả này là điều kiện để chương trình quyết định kết thúc ván đấu. Ngoài ra, việc biết được kết quả thắng, thua, và hòa sẽ giúp AI của trò chơi đưa ra đánh giá về trạng thái bàn cờ một cách đúng đắn.

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
*Parameters:*
    - `board`: Bàn đấu hiện tại.
    - `moveCount`: Số nước đi đã thực hiện. 
    - `move`: Nước đi mới nhất.
    - `playerValue`: Người chơi thực hiện nước đi.
    - `winPoint`: Đầu mút của chuỗi thắng (nếu có).
    - `getWinPoint`:
        - `true` #sym.arrow.r.double lấy đầu mút của chuỗi thắng (nếu có).
        - `false` #sym.arrow.r.double không lấy đầu mút của chuỗi thắng.

Returns:
    - ```Cpp Logic::WIN_VALUE```: Giá trị tượng trưng kết quả thắng.
    - ```Cpp Logic::DRAW_VALUE```: Giá trị tượng trưng kết quả hòa.
    - ```Cpp Logic::NULL_VALUE```: Giá trị tượng trưng kết quả vô định.

*Usage:*
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
*Parameters:*
    - `board`: Bàn đấu hiện tại.
    - `moveCount`: Số nước đi đã thực hiện. 
    - `move`: Nước đi được thực hiện.
    - `playerValue`: Người chơi thực hiện nước đi.

*Usage:*
```Cpp
GameAction::MakeMove(board, moveCount, latestMove, currentPlayer);
GameAction::UndoMove(board, moveCount, latestMove, currentPlayer);
```

=== AI
Việc thiết kết chương trình cho chế độ _Đánh với máy_ là một trong những thách thức lớn nhất của đồ án. Khác với những tính năng khác của chương trình, tính năng này đòi hỏi những mảng kiến thức chuyên biệt về các thuật toán, kĩ thuật lập trình cụ thể. Ngoài ra, việc đánh giá độ đúng/sai của chương trình, hay nói cách khác là nước đi máy tính tìm được là tốt hay xấu, sẽ phần lớn phụ thuộc vào cảm tính và sự hiểu biết của người viết. Chính vì vậy, chương trình có thể đánh hay đối với người này, nhưng đánh không tốt đối với người khác. Phần tiếp theo sẽ trình bày những kĩ thuật mà nhóm đã sử dụng cho chương tình AI.

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

=== Màn hình chính

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
    - Khó khăn trong việc thiết kế AI do có nhiều kiến thức mới, lạ
    - Chưa có kinh nghiệm trong việc thiết kế giao diện, viết ứng dụng có giao diện

== Những gì đã học được
    - Cách làm việc nhóm với git và GitHub
    - Cách sử dụng các tính năng mới của C++ 20
    - Cách sử dụng các tính năng liên quan tới đo hiệu năng, format code và debug trong Visual Studio
    - Cách làm việc nhóm hiệu quả
    - Cách lên kế hoạch, phân chia công việc
    - Cách lập trình hướng đối tượng, lâp trình đa luồng cơ bản
    

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
