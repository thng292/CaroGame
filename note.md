### Stuff to do:

- Highlight lastest move (Done)
- Fix ai clock
- Better cursor highlight (place the symbol at the cursor)
- Add avatar select screen (Done)
- Add Replay board
- _Link the screen together. NO 404 Allowed_
- Write the docs
- Undo
- Finish all the screen
- Add colors (Done)
- Tutorial
- About

### Nguyên:

- Hoàn thiện 2 file ngôn ngữ
- Viết lời cảm ơn cho báo cáo
- Tìm tmeplate cho bài thuyết trình
- Lí do hoàn thành mục tiêu cho báo cáo
- Hoàn thành text cho phần about

## PowerPoint(Khoảng 10 phút):

- Giới thiệu các màn hình (1-3 slide)
  - Có flow của màn hình
  - Nó nhanh qua các chức năng
  - Save/Load/Replay có thể để chung do gần tương tự
- Giới thiệu các phần bên dưới
  - Cơ chế Save/Load, tải file
  - Cơ chế điều hướng
  - Cơ chế load ngôn ngữ, theme, config
  - Timer
  - Thuật toán AI
  - Các tính năng đặc biệt lúc chơi

## Báo cáo:

- Giới thiệu tính năng, ý tưởng, code, cách dùng.
- Khung sườn làm theo đồ án nhập môn CNTT

## Video:

- Sử dụng gần hết các chức năng
- Script:
  - Xóa user_config
  - Mở game từ đầu
  - Mới vô chọn tiếng Ạnh (phải cho người ta thấy mới vô chỉ có tiếng Anh)
  - Mở nhạc, mở SFX
  - Vô MainMenu
  - Chuyển qua asset
  - Thêm file tiếng việt vô
  - Vô setting chuyển qua tiếng việt
  - Đổi Theme
  - Tắt nhạc
  - Mở about
  - Mở tutorial
  - Vô game chơi với máy rush (Đánh 1-2 nước, đang chơi thì mở nhạc lại)
  - Save(demo luôn lúc overwrite)
  - Tắt game bằng nút X
  - Vô game load game khác (nên tạo trước nhiều save để demo search, xóa, Load game chế độ rush, còn ít thời gian để thua)
  - Save replay
  - Chơi lại (không đánh)
  - Thoát ra mainmenu
  - Load replay
  - Thoát game

## Presentation Outline:

- Giới thiệu (Nguyên)
  - Nói qua về Gomoku
  - Có để sơ đồ di chuyển
- Các tính năng
  1. Màn hình chính (Phước)
  1. Màn hình cài đặt (Thông)
  1. Đa ngôn ngữ, chủ đề (Thông)
  1. Điều hướng trong ứng dụng (Thông)
  1. Save/load game, replay (Thông)
  1. Các chế độ chơi, chơi với máy (Vũ)
  1. Bàn cờ (Vũ)
  1. Đếm giờ (Vũ)
  1. Các tính năng đặc biệt khi chơi (Vũ)
- Kết thúc

# Cài đặt

- Có thể chỉnh sửa các thiết lập của trò chơi. Thiết lập xong có thể lưu cho lần sau
- Có các thiết lập như:
  - Bật tắt nhạc nền/hiệu ứng
  - Bật tắt các tính năng hỗ trợ khi chơi
  - Chuyển ngôn ngữ, chuyển chủ đề

# Chuyển ngôn ngữ, chủ đề

- Khiến cho việc thêm ngôn ngữ vào trò chơi dễ dàng hơn, làm cho trò chơi dễ tiếp cận hơn
- Giới thiệu qua ngôn ngữ có sẵn
- Được tải từ file bên ngoài, tìm file trong thư mục `asset/language`

- Tăng tính cá nhân hóa
- Giới thiệu các chủ đề có sẵn
- Được tải từ file bên ngoài, tìm file trong thư mục `theme`
- Hạn chế: Có thể lầm các file khác thành file ngôn ngữ
- Hạn chế: Có thể lầm các file khác thành file chủ đề

- Mở ra nhiều cách sáng tạo khác nhau
  - Ngôn ngữ động vật
  - Ẩn đi các quân cờ, lịch sử khi chơi

# Điều hướng trong ứng dụng

- Giải pháp thay thế cho việc gọi hàm trực tiếp.
- Điểm yếu của gọi hàm trực tiếp:

  - Cần phải biết chữ kí của hàm cần chuyển tới
  - Khó quản lý các màn hình, đích đến
  - Có thể bị tràn stack nếu chuyển màn hình nhiều lần
  - Nếu muốn sửa lại code thì phải chỉnh ở nhiều nơi

- Giải pháp:
  - Có một class trung tâm để quản lí các màn hình.
  - Các màn hình sẽ có 1 nhãn duy nhất
  - Khi gọi chỉ cần sử dụng nhãn
- Nhược điểm:
  - Khó truyền dữ liệu giữa các màn hình

# Save/load game, replay

- Các màn hình có cấu trúc tương tự nhau
- Gồm các phần:
  - Danh sách các file
    - Tên file lưu và thời gian lưu
    - Chia thành nhiều trang
  - Ô nhập văn bản để tìm kiếm hoặc nhập tên
    - Tìm kiếm mỗi khi nhập từ mới
  - Các hướng dẫn
