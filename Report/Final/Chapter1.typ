= Tổng quan về trò chơi

== Giới thiệu về trò chơi

=== Trò chơi Cờ Caro (Gomoku)

Cờ Caro @Caro hay còn gọi là Gomoku @Gomoku là một trò chơi đối kháng có tính chiến thuật cao. Trò chơi được chơi trên một bàn cờ vuông với kích thước tiêu chuẩn là 15x15 ô (trong trò chơi này, do một vài giới hạn kĩ thuật nên bàn cờ sẽ có kích thước là 13x13).

Trò chơi có nhiều phiên bản khác nhau với các luật chơi khác nhau. Trong trò chơi này, chúng em đã sử dụng luật chơi như sau:
    - Hai người chơi lần lượt đặt các quân cờ của mình trên bàn cờ. 
    - Người chơi nào đặt được 5 quân cờ liên tiếp theo chiều ngang, dọc hoặc chéo sẽ thắng cuộc. 
    - Nếu không có ai thắng khi không còn nước đi khả thi thì trò chơi kết thúc với kết quả hòa.

Ngoài ra, để tăng tính đa dạng và thêm phần thú vị cho trò chơi, chúng em còn bổ sung thêm chế độ chơi mới: tốc độ (Rush). Trong chế độ này, người chơi cần phải tập trung hơn, suy nghĩ nhanh hơn để chiến thắng. Luật chơi như sau:
    - Người chơi sẽ có một khoảng thời gian nhất định để suy nghĩ và thực hiện nước đi của cả ván đấu.
    - Nếu người chơi không đánh được nước đi trong thời gian giới hạn thì người chơi đó sẽ thua cuộc.
    - Có ba khoảng thời gian khác nhau để người chơi lựa chọn: 1 phút, 5 phút và 15 phút.

#pagebreak()
=== Các yêu cầu về tính năng
    - Có thể lưu, tải trò chơi đang chơi
    - Nhận biết được thắng, thua, hòa
    - Xử lí hiệu ứng thắng, thua, hòa
    - Xử lí giao diện màn hình khi chơi
    - Xử lí màn hình chính
    - Game có nhiều ngôn ngữ, người chơi có thể thêm được ngôn ngữ mới
    - Có thể tải được các theme(chủ đề) bên ngoài
    - Người chơi có thể bât/tắt các tính năng cơ bản, có thể lưu lại các thiết lập
    - Có thể lưu và phát lại các trò chơi đã hoàn thành
    - Có nhiều chế độ chơi, chơi với máy

=== Thông tin chung về trò chơi
#figure(
    caption: "Thông tin chung về trò chơi",
    table(
        columns: (auto, auto),
        inset: 8pt,
        [*Tên trò chơi*], [Cờ Caro],
        [*Môi trường phát triển và thử nghiệm*], [Visual Studio 2022],
        [*Khả dụng trên nền tảng*], [Windows],
        [*Source code*], link("https://github.com/thng292/CaroGame")
    )
)

#pagebreak()
=== Sơ đồ di chuyển của trò chơi

#figure(
    image("asset/caro.svg", width: 100%),
    caption: [Sơ đồ di chuyển của trò chơi]
)

== Mô tả về các tính năng của trò chơi

=== Menu chính
Đây là "Menu Chính" của trò chơi. Người chơi có thể chọn các chức năng khác nhau bằng cách chọn vào các mục tương ứng. Các mục chức năng bao gồm:
    - Trò chơi mới: Bắt đầu một ván đấu mới.
    - Ván đấu đã lưu: Tải lại một ván đấu đã lưu.
    - Phát lại: Phát lại một ván đấu đã hoàn thành.
    - Cài đặt: Tùy chỉnh các thiết lập của trò chơi.
    - Hướng dẫn: Hướng dẫn cách chơi và cách tương tác với các thành phần giao diện của trò chơi.
    - Thông tin: Thông tin về tác giả.
    - Thoát: Thoát trò chơi.

Phía trên bên phải của "Menu Chính" là phiên bản của trò chơi.
#figure(
    image("asset/MainMenu.png", width: 100%),
    caption: [Menu chính]
)

=== Giao diện và các tính năng đặc biệt khi chơi

==== Giao diện màn hình khi chơi
Giao diện màn hình khi chơi trò chơi là một phần rất quan trọng của trò chơi vì nó là nơi mà người chơi dành nhiều thời gian tương tác với trò chơi nhất. Khi thiết kế màn hình này, chúng em đã phải suy nghĩ rất kĩ, trên màn hình sẽ hiện thông tin nào, hiện ra sao và sắp xếp như thế nào. Cuối cùng, chúng em đã thiết kế nó như sau:

#figure(
    image("asset/Board.png", width: 100%),
    caption: [Giao diện màn hình khi chơi]
)

Trong trò chơi này, giao diện màn hình khi chơi được chia thành 3 phần chính:
    - Phần bàn cờ (bên trái): Khu vực chơi chính
    - Phần trạng thái trận đấu (phía trên bên phải): là nơi hiển thị các thông tin về ván đấu như: thời gian đã chơi (chế độ thường), thời gian còn lại (chế độ tốc độ), số trận đấu đã thắng.
    - Phần thông tin người chơi (dưới phần trạng thái trận đấu): là nơi hiển thị các thông tin về người chơi như: tên người chơi, ảnh đại diệnm lượt hiện tại của người nào.
    - Phần lịch sử nước đi (dưới phần thông tin người chơi): là nơi hiển thị các nước đi đã được thực hiện trong trận đấu. Có thể cuộn lên, xuống để xem toàn bộ lịch sử nước đi.
    - Phần hướng dẫn (phía dưới bên phải): là nơi hiển thị các nút để tương tác với trò chơi.

==== Các tính năng đặc biệt khi chơi
Để tăng thêm trải nghiệm cho người chơi, chúng em đã thêm vào một số tính năng đặc biệt.

===== Chơi với máy
Chơi với máy là một tính năng vô cùng hữu ích khi người chơi không tìm được người chơi khác để chơi cùng. Có 3 độ khó: Dễ, Trung bình, Khó. Độ khó của máy được xác định bằng độ sâu tìm kiếm của thuật toán. Độ khó cao thì máy sẽ chơi tốt hơn, nhưng sẽ mất nhiều thời gian để tính toán hơn.
Để chơi với máy, khi chọn chế độ chơi, người chơi cần chọn chế độ "PvE". Sau đó, người chơi chọn độ khó của máy.
Máy tính sẽ có ảnh đại diện đặc biệt để phân biệt với người chơi.

#grid(
    columns: (1fr, 1fr),
    rows: (auto),
    gutter: 8pt,
    figure(
        image("asset/ModePvE.png", width: 80%, height: 180pt, fit: "contain"),
        caption: [Chọn chế độ chơi với máy]
    ),
    figure(
        image("asset/AIDifficulty.png", width: 80%, height: 180pt, fit: "contain"),
        caption: [Chọn độ khó của máy]
    )
)

#figure(
    image("asset/AIBoard.png", width: 100%),
    caption: [Giao diện màn hình khi chơi với máy]
)

===== Chọn ảnh đại diện
Người chơi có thể chọn ảnh đại diện của mình khi tạo trò chơi mới. Ảnh đại diện sẽ được hiển thị trên màn hình khi chơi, trong phần "thông tin người chơi". trò chơi có tổng cộng 8 ảnh đại diện cho người chơi chọn lựa và một ảnh đại diện đặc biệt dành cho máy. Các ảnh đại diện được lấy cảm hứng từ các nhân vật hoạt hình nổi tiếng để tạo cảm giác thân thuộc cho người chơi.

#figure(
    image("asset/AvatarSelect.png", width: 100%),
    caption: [Chọn ảnh đại diện cho 2 người chơi]
)

===== Gợi ý
Tính năng này sử dụng AI để gợi ý cho người chơi nước đi tốt tiếp theo.
Người chơi có thể kiểm tra chức gợi ý có được bật không bằng cách kiểm tra góc dưới bên phải màn hình chơi xem phần hoàn tác đã bật hay chưa.
Mặc định thì tính năng gợi ý sẽ được bật sẵn, nhưng người chơi có thể tắt nó đi trong phần cài đặt.
#figure(
    image("asset/offhint.png", width: 60%),
    caption: [Tắt chức năng gợi ý]
)

Khi cần, người chơi có thể nhấn phím `H` để sử dụng gợi ý. Nước đi gợi ý sẽ được làm nổi bật lên.
#figure(
    image("asset/usehint.png", width: 40%),
    caption: [Nước đi gợi ý]
)

===== Nổi bật nước mới đi
Nước mới đi sẽ được làm nổi bật lên giúp người chơi dễ dàng nhận biết và theo dõi.
#grid(
    columns: (1fr, 1fr),
    rows: (auto),
    gutter: 8pt,
    figure(
        image("asset/LatestMoveX.png", width: 80%, height: 190pt),
        caption: [Nước mới đi bên X]
    ),
    figure(
        image("asset/LatestMoveO.png", width: 80%, height: 190pt),
        caption: [Nước mới đi bên O]
    )
)

===== Cảnh báo nước 4
Khi 4 quần cờ liên tiếp nối với nhau tạo thành một đường, các quân cờ đó sẽ được làm nổi bật bởi màu khác để người chơi có thể dễ dàng nhận biết từ đó đưa ra các nước cờ ngăn chặn đối phương. Mặc định tính năng này sẽ được bật sẵn, nhưng người chơi có thể tắt nó đi trong phần cài đặt.
#figure(
    image("asset/FourOff.png", width: 60%),
    caption: [Cài đặt cảnh báo nước 4]
)
#figure(
    image("asset/FourWarn.png", width: 40%),
    caption: [Cảnh báo các quân cờ nước 4]
)
===== Hoàn tác nước đi
Đôi khi người chơi, vì nhiều lí do, lỡ ấn đánh nhầm nước và muốn hoàn tác lại nước đi vừa thực hiện. Khi đó tính năng hoàn tác nước đi sẽ trở nên rất hữu ích. Mặc định tính năng này sẽ được bật sẵn, nhưng người chơi có thể tắt nó đi trong phần cài đặt.
Người chơi có thể kiểm tra chức năng hoàn tác nước đi có được bật không bằng cách kiểm tra góc dưới bên phải màn hình chơi xem tính năng hoàn tác có được bật hay chưa.

#figure(
    image("asset/UndoOff.png", width: 60%),
    caption: [Cài đặt chức năng hoàn tác nước đi]
)

Khi cần, người chơi có thể nhấn phím `Z` để hoàn tác nước đi. Nước đi sẽ được hoàn tác lại và quân cờ sẽ được đưa về trạng thái trước khi đánh nước đó.

#grid(
    columns: (1fr, 1fr),
    rows: (auto),
    gutter: 8pt,
    figure(
        image("asset/BeforeUndo.png", width: 80%),
        caption: [Trước khi hoàn tác nước đi]
    ),
    figure(
        image("asset/AfterUndo.png", width: 80%),
        caption: [Sau khi hoàn tác nước đi]
    )   
)

===== Đi nháp
Chức năng này cho phép người chơi đi các nước đi mà không ảnh hưởng tới diễn biến ván cờ, cho phép người chơi thoải mái tính toán các nước đi tiếp theo. Khi bật đi nháp, con trỏ sẽ chuyển màu, người chơi có thể tùy thích đi các nước đi. Các nước đi nháp sẽ có màu khác với màu của quân cờ hiện tại. Khi tắt đi nháp, các nước đi nháp sẽ bị xóa, trả lại ván cờ như lúc trước khi bật đi nháp.
#grid(
    columns: (1fr, 1fr),
    rows: (auto),
    gutter: 8pt,
    figure(
        image("asset/GhostMoveOn.png", width: 80%),
        caption: [Các nước đi nháp]
    ),
    figure(
        image("asset/GhostMoveOff.png", width: 80%),
        caption: [Khi tắt đi nháp]
    )
)

=== Các chế độ chơi

==== Chế độ chơi Thường

Chế độ không thể thiếu của trò chơi. Cổ điển và đơn giản. Ở chế độ này, trò chơi hiển thị thời gian mà người chơi sử dụng để suy nghĩ ở phần trạng thái ván đấu.

#figure(
    image("asset/NormalMode.png", width: 100%),
    caption: [Giao diện màn hình khi chơi chế độ Thường]
)

==== Chế độ chơi Rush

Để thêm phần thú vị cho trò chơi, chúng em đã thêm vào chế độ Rush. Ở chế độ này, trò chơi hiển thị thời gian còn lại của người chơi ở phần trạng thái ván đấu.

#figure(
    image("asset/RushMode.png", width: 100%),
    caption: [Giao diện màn hình khi chơi chế độ Rush]
)

=== Xử lí, hiệu ứng thắng, thua, hòa
Nếu có người thắng ván đấu, trò chơi sẽ làm nổi bật lên chuỗi 5 quân cờ của người thắng, sau đó, trò chơi sẽ đợi người dùng nhấn phím `Space` để chuyển sang màn hình kết quả ván đấu.

#figure(
    image("asset/OWin.png", width: 100%),
    caption: [Giao diện màn hình khi O thắng]
)
#figure(
    image("asset/XWin.png", width: 100%),
    caption: [Giao diện màn hình khi X thắng]
)

Sau khi nhấn `Space`, người chơi sẽ được chuyển sang màn hình kết quả ván đấu. Trong màn hình này, người chơi có thể xem lại thông tin trận đấu như: số nước đi, thòi gian đã chơi, thời gian còn lại, người chơi đã thắng bao nhiêu trận.

#figure(
    image("asset/GameResult.png", width: 100%),
    caption: [Giao diện màn hình kết quả ván đấu]
)

=== Lưu/tải ván đấu đang chơi, phát lại ván đấu đã chơi xong

==== Lưu ván đấu đang chơi
Người chơi có thể lưu lại ván đấu mình đang chơi bằng cách truy cập vào menu "Tạm dừng" (ấn phím `ESC`) và chọn mục "Lưu trò chơi" để mở menu "Lưu". Các bản lưu của người chơi cùng thời gian lưu sẽ hiện ra. Các bản lưu được sắp xếp theo thứ tự giảm dần của thời gian lưu, nếu người chơi có quá nhiều bản lưu thì trò chơi sẽ chia thành nhiều trang, người chơi có thể chuyển qua lại giữa các trang. Ở phía dưới các bản lưu là trang hiện hiên tại và tổng số trang. Phía dưới menu là nơi để người chơi nhập tên cho bản lưu, khi người chơi nhập tên, trò chơi sẽ đưa các bản lưu có tên liên quan tới đầu vào của người chơi. Sau khi nhấn lưu, trò chơi sẽ thông báo lưu thành công hay thất bại.

#figure(
    image("asset/PauseMenu.png", width: 40%),
    caption: [Menu "Tạm dừng"]
)
#figure(
    image("asset/SaveGame.png", width: 60%),
    caption: [Menu "Lưu"]
)

Trong trường hợp người chơi nhập tên bản lưu trùng với tên của một bản lưu khác, trò chơi sẽ thông báo cho người chơi và hỏi người chơi có muốn ghi đè lên bản lưu cũ hay không. Ngoài ra, người chơi cũng có thể xóa bản lưu.

#grid(
    columns: (1fr,1fr),
    rows: (auto),
    figure(
        image("asset/Overwrite.png", width: 100%),
        caption: [Thông báo ghi đè bản lưu]
    ),
    figure(
        image("asset/Delete.png", width: 100%),
        caption: [Thông báo xóa bản lưu]
    )
)

==== Tải trò chơi đã lưu
Người chơi có thể tải ván đấu đã lưu bằng cách truy cập vào "Menu Chính" và chọn mục "Ván đấu đã lưu". Giao diện của menu này tương tự như menu "Lưu", để tải bản lưu, người chơi tìm và chọn bản lưu đó. Để thuận tiện hơn cho người chơi, chúng em đã thêm vào ô tìm kiếm ở dưới menu, khi người chơi nhập vào ô tìm kiếm, trò chơi sẽ đưa các bản lưu có tên liên quan tới đầu vào của người chơi lên trên. Khi tải bản lưu, nếu việc tải bản lưu bị lỗi, trò chơi sẽ thông báo lỗi và người chơi có thể chọn bản lưu khác. Nếu tải thành công, trò chơi sẽ chuyển sang màn hình chơi và người chơi có thể tiếp tục ván đấu. Ngoài ra người chơi cũng có thể xóa bản lưu như ở menu "Lưu".

#figure(
    image("asset/LoadGame.png", width: 60%),
    caption: [Menu "Ván đấu đã lưu"]
)

==== Phát lại trò chơi đã chơi xong
Chức năng này cũng tương tự như tính năng lưu và tải trò chơi. Sau khi chơi xong, người chơi có thể muốn lưu lại quá trình chơi của ván đấu để sau này phát lại, nên chúng em đã thêm bào tính năng lưu và phát lại các ván đấu đã chơi.
Sau khi kết thúc ván đấu, trò chơi sẽ hỏi người chơi có muốn lưu bản phát lại hay không. Nếu chọn có, người chơi sẽ được dẫn tới menu "Phát lại", menu này tương tự như menu "Ván đấu đã lưu", người chơi có thể lưu, xóa các bản phát lại của mình.

Để phát bản phát lại, tại "Menu Chính", người chơi chọn vào mục "Phát lại" và chọn bản phát lại cần phát. Nếu tải bản phát lại thành công, trò chơi sẽ chuyển sang màn hình phát lại và người chơi có thể phát lại ván đấu, nếu thất bại sẽ có thông báo lỗi và người chơi có thể chọn bản phát lại khác.

#figure(
    image("asset/ReplaySave.png", width: 60%),
    caption: [Menu "Phát lại"]
)

Tại đây, người chơi có thể xem lại trận đấu của mình.
#figure(
    image("asset/ReplayView.png", width: 100%),
    caption: [Màn hình chơi bản phát lại]
)

=== Đa ngôn ngữ
Khi vào trò chơi lần đầu sẽ có bảng thông báo xuất hiện yêu cầu bạn lựa chọn ngôn ngữ cho trò chơi. Ngôn ngữ có sẵn trong trò chơi gồm tiếng Việt và tiếng Anh. Người chơi có thể thêm file ngôn ngữ khác ở mục asset/language để có thể lựa chọn thêm ngôn ngữ đó.

#figure(
    image("asset/FirstLangVi.png", width: 40%),
    caption: [Lựa chọn ngôn ngữ tiếng Việt]
)
#figure(
    image("asset/FirstLangEn.png", width: 40%),
    caption: [Lựa chọn ngôn ngữ tiếng Ạnh]
)

Ngoài ra người chơi còn có thể chỉnh ngôn ngữ trong phần cài đặt của trò chơi.
#figure(
    image("asset/LangSetting.png", width: 60%),
    caption: [Lựa chọn ngôn ngữ ở phần cài đặt]
)

=== Thay đổi Chủ đề
Để tăng tính cá nhân hóa cho trò chơi, chúng em đã thêm tính năng thay đổi chủ đề của trò chơi.
Người chơi có thể thay đổi chủ đề của trò chơi trong phần cài đặt. Chủ đề có sẵn trong trò chơi gồm Default, Mystic, Nature, Mystery. Ngoài ra người chơi còn có thể thêm file chủ đề khác vào thư mục `themes`. Khi tải chủ đề lỗi, trò chơi sẽ áp dụng chủ để Default.
#grid(
    columns: (1fr, 1fr),
    rows: (auto, auto),
    gutter: 8pt,
    figure(
        image("asset/DefaultTheme.png", width: 100%),
        caption: [Default Theme]
    ),
    figure(
        image("asset/MysticTheme.png", width: 100%),
        caption: [Mystic Theme]
    ),
    figure(
        image("asset/NatureTheme.png", width: 100%),
        caption: [Nature Theme]
    ),
    figure(
        image("asset/MysteryTheme.png", width: 100%),
        caption: [Mystery Theme]
    )
)