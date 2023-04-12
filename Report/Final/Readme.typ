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
