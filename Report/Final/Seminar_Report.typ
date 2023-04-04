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

=== Mục tiêu đề ra

=== Thông tin chung về trò chơi
Link souce code, chạy trên nền tảng nào, ...

== Sơ lược về các tính năng của game

== Sơ dồ di chuyển

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
Phước

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