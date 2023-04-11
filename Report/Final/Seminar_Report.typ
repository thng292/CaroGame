#set document(
	title: "Đồ án kĩ thuật lập trình nhóm 11",
	author: "Nhóm 11 - 22CLC01"
)

#set text(
  font: "Time News Roman",
  size: 14pt,
  lang: "vi"
)

#set page(
  paper: "a4",
  header: align(right)[
    Đồ án kĩ thuật lập trình nhóm 11
  ],
  numbering: "1"
)

#set par(
	linebreaks: "optimized",
	justify: true
)

#set heading(
  numbering: "1.1."
)

#set figure(
	numbering: "1.1"
)

#set raw(
	lang: "cpp"
)

#show "Interface" : strong
#show "Usage" : strong
#show "Parameters" : strong
 
#page(numbering: none)[
#place(
    center + horizon,
    block(
        width: 100%,
        height: 100%,
        stroke: 2pt,
		[
		#align(center + top)[
			#pad(top: 16pt)[
				*TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN\
				KHOA CÔNG NGHỆ THÔNG TIN*
			]
		],
		#place(
			center + horizon,
			[

			#image("HCMUS_Logo.png", width: 40%),

			#align(center, text(20pt, pad(rest: 32pt)[
				*ĐỒ ÁN MÔN HỌC\
				KĨ THUẬT LẬP TRÌNH\
				ĐỀ TÀI: XÂY DỰNG GAME CỜ CARO*
			]))

			#align(center)[
				*Nhóm 11*\
				22127401 - Nguyễn Quang Thông\
				22127298 - Hoàng Trung Nguyên\
				22127339 - Võ Nhật Phước\
				22127463 - Nguyễn Anh Vũ
			]

			#pad(
				rest: 32pt,
				align(center)[
				*Giáo Viên Hướng Dẫn: Trương Toàn Thịnh*
			])
			]
		),
		#align(center + bottom)[
			#pad(bottom: 16pt, text(size: 10pt)[
				*Thành Phố Hồ Chí Minh, Ngày 03 tháng 04 năm 2023*
			])
		]
		]
    )
)
]

#pagebreak()

#align(center, heading(numbering: none)[Lời nói đầu])
#pagebreak()

#align(center, heading(numbering: none)[Lời cảm ơn])
#pagebreak()

#heading(numbering: none)[Mục lục]
#outline(
	title: none,
    indent: true
)
#pagebreak()

#heading(numbering: none)[Mục lục hình]
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

= Hướng dẫn sử dụng

== Hiển thị hình ảnh
```typst
#figure(
	image("HCMUS_Logo.png", width: 40%),
	caption: [Test fig]
)
```

*Nhớ bỏ caption vô không là cái mục lục hình bị lỗi*
#figure(
	image("HCMUS_Logo.png", width: 40%),
	caption: [Test fig]
)

== Code có highlight (Paste code ít thôi, lấy cái nào quan trọng á)
```Cpp
	while (1) {
        auto tmp = InputHandle::Get();
        if (tmp == L"b" || tmp == L"B") {
            return NavHost.Back();
        }
        if (tmp == L"\r") {
            system(
                "rundll32 url.dll,FileProtocolHandler "
                "https://github.com/thng292/CaroGame"
            );
        }
    }
```

= Table
#table(
    columns: (1fr, 1fr),
    inset: 5pt,
    align: horizon,
    [*Thành viên*], [*Đánh giá*],
    [#lorem(10)], [#lorem(10)],
)
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

== Sơ dồ di chuyển
Phước

= Chi tiết các chức năng

== Logic

=== Chơi hiệu ứng, nhạc nền

Các file âm thanh được đặt trong thư mục asset/audio và có thể truy cập bằng các `enum`. Các `enum` được map sang một mảng chứa tên các file âm thanh

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
    GameMove,
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
        L"GameMove.wav",
        L"GamePlaceMove.mp3",
        L"GameStart.wav",
        L"Pause.wav",
        L"Warning.mp3"
    };
```
)

==== Hàm PlayAndForget 
Hàm này sử dụng API PlaySound để chơi nhạc. Được dùng để chơi những âm thanh ngắn, dung lượng nhỏ dưới 100kb. Khi gọi hàm sẽ tự load file vào memory, chơi và đóng file. Do phải load cả file vào bộ nhớ nên khi chơi có độ delay cao và chỉ có thể mở được file `wav`. Được ứng dụng để chơi các âm thanh liên quan tới giao diện, các âm thanh không quan tâm tới độ trễ. Hàm nằm trong `namespace Audio`, file `Audio.h`

Interface:
```Cpp
bool PlayAndForget(Sound sound, bool wait)
```

Parameters:
	- Sound: âm thanh cần chơi
	- wait:\ 
		true  => phát âm thanh một cách đồng bộ (synchronous)\
		false => phát âm thanh một cách bất đồng bộ (asynchronous)

Usage:
```Cpp
	Audio::PlayAndForget(Audio::Sound::MenuSelect);
```

==== Class AudioPlayer

Class này sử dụng #strong(`Media Control Interface`) (`MCI`) để chơi nhạc, chơi được các file âm thanh định dạng `mp3` và `wav`. Chơi được các file lớn, ít delay do không cần load hết file vào bộ nhớ. Được dùng để chơi nhạc nền hoặc file `mp3`.

Interface:
```
class AudioPlayer {
    AudioPlayer();
    AudioPlayer(Sound song); // Khởi tạo và mở file
    int Open(Sound song);    // Mở file. Có thể dùng để đổi file cần chơi
    Sound getCurrentSong() const;
    int Play(bool fromStart, bool repeat) const; // Chơi
    int Pause() const;      // Tạm dừng
    int Resume() const;     // Tiếp tục
    int Stop() const;       // Dừng chơi và trả con trỏ về đầu
    int Close();            // Đóng file đang mở
	~AudioPlayer();         // Đóng file đang mở
}
```

Parameters:
	- song: âm thanh cần chơi
	- fromStart:\
		true  => chơi từ đầu\
		false => chơi tiếp tại vị trí con trỏ
	- repeat: \
		true => lặp lại khi kết thúc

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
=== Đọc, ghi, tìm file
Thông

=== Ngôn ngữ
Thông

=== Cài đặt
Thông

=== Điều hướng trong ứng dụng
Thông

=== Đồng hồ
Thông

=== Hàm trung gian hỗ trợ vẽ giao diện
Thông

=== Nhận biết thắng thua
Vũ

=== Các tương tác với bàn cờ
Vũ

=== AI
Vũ

sdhfiuashksj

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
Phước

== Những gì đã học được
	- Cách làm việc nhóm với git và GitHub
	- Cách sử dụng các tính năng mới của C++
	- Cách sử dụng các tính năng liên quan tới đo hiệu năng, format code và debug trong Visual Studio
	- Cách làm việc nhóm hiệu quả
	- Cách lên kế hoạch, phân chia công việc
	- Học được cách vẽ biểu đồ di chuyển cho ứng dụng


== Các kinh nghiệm rút ra
	- Không nên viết code mà không thiết kế trước
	- Nên viết code theo một quy chuẩn nhất định và đồng bộ trong 1 dự án

== Lí do hoàn thành mục tiêu
Nguyên

== Hướng phát triển ứng dụng
	- Có thể chơi 2 người qua mạng lan
	- Thêm nhiều ngôn ngữ mới
	- Thêm nhiều chủ đề hơn
	- Hiện lợi thế của 2 bên
	- Đưa game lên nhiều nền tảng khác