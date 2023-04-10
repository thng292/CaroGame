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

=== Các màn hình hỗ trợ khác

= Đánh giá thành viên

= Kết luận

== Kết quả đạt được

=== Ưu điểm của trò chơi
Phước
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