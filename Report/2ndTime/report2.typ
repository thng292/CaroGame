#set page(
  paper: "a4",
  header: align(right)[
    Báo cáo lần 2 nhóm 11
  ],
  numbering: "1",
)

#set heading(
    numbering: "1.a)",
)

#set text(
    font: "Time News Roman",
    size: 12pt
)

#place(
    center + horizon,
    block(
        width: 100%,
        height: 100%,
        stroke: 2pt,
        place(
            center + horizon,
            [
            #align(center, text(32pt, pad(rest: 32pt)[
                *Báo cáo đồ án môn học\
                lần 2 của nhóm 11*
            ]))

            #align(center)[
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
        )
    )
)


#pagebreak()

= Table of Contents
#outline(
    title: none,
    indent: true
)

#pagebreak()

= Nhiệm vụ đã giao:

== Tuần 1

#table(
    columns: (auto, auto, auto, auto, auto),
    inset: 5pt,
    align: horizon,
    [*Thành viên*], [*Công Việc*], [*Yêu Cầu*], [*Thời gian*], [*Đánh giá*],
    [Nguyễn Quang Thông], [Viết Màn hình để save và load game], [Có thể save và load game, có thể search, xóa file], [1-7/3], [Hoàn thành tốt],
    [Võ Nhật Phước], [Thiết kế logo cho game ở MainMenu], [Logo đẹp, độc lạ], [1-7/3], [Hoàn thành tốt],
    [Nguyễn Anh Vũ], [Hoàn thành bản mẫu lần 1 của AI], [AI đánh tốt ở mức dễ, trung bình, sử dụng ít tài nguyên], [1-7/3], [Hoàn thành tốt],
    [Hoàng Trung Nguyên], [Bổ sung thêm nhãn vào file ngôn ngữ anh], [Hoàn thành các nhãn còn thiếu], [1-7/3], [Hoàn thành tốt],
)

== Tuần 2

#table(
    columns: (auto, auto, auto, auto, auto),
    inset: 5pt,
    align: horizon,
    [*Thành viên*], [*Công Việc*], [*Yêu Cầu*], [*Thời gian*], [*Đánh giá*],
    [Nguyễn Quang Thông], [Viết Màn hình để save và load game replay, viết màn hình Settings], [Có thể save và load game replay, có thể search, xóa file, có thể truy cập và chỉnh sửa thiết lập của game], [8-14/3], [Hoàn thành tốt],
    [Võ Nhật Phước], [Thiết kế siêu nhân đỏ ở MainMenu], [Siêu nhân đẹp, độc lạ], [8-14/3], [Hoàn thành tốt],
    [Nguyễn Anh Vũ], [Hoàn thành bản mẫu các màn hình liên quan đến việc chơi game], [Có thể chọn được độ khó, chơi được game, hiện được đồng hồ], [8-14/3], [Hoàn thành tốt],
    [Hoàng Trung Nguyên], [Bạn có việc bận], [-], [8-14/3], [-],
)

== Tuần 3

#table(
    columns: (auto, auto, auto, auto, auto),
    inset: 5pt,
    align: horizon,
    [*Thành viên*], [*Công Việc*], [*Yêu Cầu*], [*Thời gian*], [*Đánh giá*],
    [Nguyễn Quang Thông], [Sửa các lỗi liên quan tới Timer], [Timer không còn bị delay khi destroy], [15-21/3], [Hoàn thành tốt],
    [Võ Nhật Phước], [Thiết kế siêu nhân xanh ở MainMenu], [Siêu nhân xanh đẹp, độc lạ], [15-21/3], [Hoàn thành tốt],
    [Nguyễn Anh Vũ], [Hoàn thành các màn hình liên quan đến việc chơi game], [Các màn hình đúng với thiết kế đã chọn], [15-21/3], [Hoàn thành tốt],
    [Hoàng Trung Nguyên], [Chọn nhạc mới cho game], [Nhạc phù hợp với gameplay và nhịp độ trò chơi], [15-21/3], [Hoàn thành tốt],
)


== Tuần 4

#table(
    columns: (auto, auto, auto, auto, auto),
    inset: 5pt,
    align: horizon,
    [*Thành viên*], [*Công Việc*], [*Yêu Cầu*], [*Thời gian*], [*Đánh giá*],
    [Nguyễn Quang Thông], [Sửa các lỗi liên quan tới timer, làm cho game chơi được nhạc nền], [Game có thể chơi được nhạc nền, Timer không còn bị delay hoặc lỗi khi thread bị destroy], [22-28/3], [Hoàn thành tốt],
    [Võ Nhật Phước], [Vẽ các ảnh đại diện], [Ảnh đẹp, độc lạ.], [22-28/3], [Hoàn thành tốt],
    [Nguyễn Anh Vũ], [Sửa các lỗi ở màn hình chơi game, làm cho AI hoạt động ổn định], [AI hoạt động tốt ở mức hard, sửa xong các lỗi đã biết ở màn hình chơi game], [22-28/3], [Hoàn thành tốt],
    [Hoàng Trung Nguyên], [Bổ sung thêm nhãn vào file ngôn ngữ anh], [Hoàn thành các nhãn còn thiếu], [22-28/3], [Hoàn thành tốt],
)

= Các tính năng đã hoàn thành:
- Các tính năng cơ bản của trò chơi.
- Thêm các ảnh đại diện cho trò chơi.
- Chọn xong các đoạn nhạc nền, và nhạc hiệu ứng.
- AI chơi tốt ở các độ khó, sử dụng ít tài nguyên.

= Kế hoạch cho tương lai:
- Cho phép người dùng chọn ảnh đại diện khi chơi.
- Thêm khả năng lưu và xem lại các game đã chơi.
- Cải thiện trải nghiệm người dùng trong lúc chơi.
- Hoàn thiện các file ngôn ngữ.
- Cho phép người chơi đi lại nước đi cũ.
- Viết các phần hướng dẫn và giới thiệu.

