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

#set heading(
  numbering: "1.1."
)

#set figure(
	numbering: "1.1"
)

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

#heading(numbering: none)[Lời cảm ơn]
#pagebreak()

= Mục lục
#outline(
	title: none,
    indent: true
)
#pagebreak()

= Mục lục hình
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
Thông

=== Thông tin chung về trò chơi
Nguyên
Link souce code, chạy trên nền tảng nào, ...

== Sơ lược về các tính năng của game
Thông

== Sơ dồ di chuyển
Phước

= Chi tiết các chức năng

== Logic

=== Chơi hiệu ứng, nhạc nền
Thông

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

=== Các bước thiết lập ban đầu
Thông

=== Hướng dẫn
Thông

=== Màn hình chính
==== Logo 

- Height: 6
- Width: 54
- Color: Đen, đỏ, xanh
- Căn giữa
#figure(
  image("asset/logo_caro.PNG", width: 70%),
  caption: [
    Logo Caro.
  ],
)

==== Main Menu

- Height: 11
- Width: 21
- Color: Đen
- Căn giữa
#figure(
  image("asset/main_menu.PNG", width: 70%),
  caption: [
    Main Menu
  ],
)

==== Trang trí

- Logo Deadpool
	- Height: 24
	- Width: 27
	- Color: Đỏ, đen, xám, vàng, nâu, trắng
	- Căn trái

- Logo Captain America
	- Height: 24
	- Width: 33
	- Color: Xanh, đỏ, xám, đen, nâu, vàng
	- Căn phải


#grid(
	columns: (50%, 50%),
	rows: (auto),
	figure(
	image("asset/logo_deadpool.PNG", height: 50%),
	caption: [
		Logo Deadpool
	],
	),
	figure(
	image("asset/logo_captain_american.PNG", height: 50%),
	caption: [
		Logo Captain America
	],
	)
)

=== Giới thiệu
Nguyên

=== Cài đặt
Thông

=== Các màn hình lưu, tải game và replay
Thông

=== Các màn hình liên quan đến trò chơi chính
Vũ

= Đánh giá thành viên

= Kết luận

== Kết quả đạt được

=== Ưu điểm của trò chơi
- Avatar pokemon quen thuộc tạo cảm giác quay về tuổi thơ cho người chơi
- Chế độ đánh game có tính thời gian, thoải mái lựa chọn thời gian giới hạn
- Đồ họa xịn xò, có nhiều sự đầu tư, màu sắc hài hòa, dễ nhìn, dễ sử dụng
- Hướng dẫn cụ thể, chi tiết, dễ đọc - dễ hiểu - dễ sử dụng
- Nhiều chế độ đánh với máy: dễ, vừa, khó
- Có thể xem lại lịch sử trò chơi
- Hiệu ứng âm thanh sống động

=== Khuyết điểm của trò chơi
Phước

== Những gì đã học được
4 người cùng làm phần này ai học được gì ghi vô rồi chỉnh lại sau

== Các kinh nghiệm rút ra
4 người cùng làm phần này ai học được gì ghi vô rồi chỉnh lại sau

== Lí do hoàn thành mục tiêu
Nguyên

== Hướng phát triển ứng dụng
4 người suy nghĩ