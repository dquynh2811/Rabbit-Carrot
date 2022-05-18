# Báo cáo bài tập lớn môn Lập trình nâng cao - INT2215_1
- Họ và tên: **Phạm Thị Diễm Quỳnh**
- MSSV: **21020087**
- Tựa game: **Rabbit & Carrot**

## 1. Cách lấy và chạy chương trình:
- Bước 1: Download từ github file zip chứa toàn bộ code & thư viện, hình ảnh, âm thanh từ github
- Bước 2: Giải nén, tìm và chạy file `Rabbit & Carrot.exe` để chạy game.

## 2. Mô tả chung về trò chơi, các ý tưởng chính:
- Trò chơi là hành trình thỏ vượt chướng ngại vật đi tìm carrot, được điều khiển bằng 3 phím - up, left, right.
- Ý tưởng chính: Bẫy sẽ chỉ hiện ra khi thỏ tới rất gần nó (phản xạ của người chơi không nhanh sẽ không tránh được). Sử dụng dữ liệu từ map tự tạo để tạo độ khó cho game.

## 3. Mô tả các chức năng đã cài đặt

[Video minh họa](https://www.youtube.com/watch?v=uVNvpU1Bqng)

**Mô tả**:  
- Tại Menu có nhạc nền và nút `start`, `quit` để vào/thoát game.
- Thỏ có thể tiến, lùi, bay và đứng lại trên nền (gạch, ống), rơi tự do nếu đang trên không trung mà ko ấn nút up. 
- Bẫy sẽ hiện khi thỏ đứng gần nơi đặt bẫy, đây cũng là điểm nhấn và là điểm cần xử lý nhiều nhất trong project của em. 
- Mỗi lần vào game từ menu hoặc sang 1 level sẽ có 1 background khác nhau. Nếu dùng reload, background sẽ giữ nguyên như cũ.
- Có âm thanh cho các thao tác (lúc bay, chạm chướng ngại vật).
- Game có 5 level. Từ menu vào sẽ vào level 1. Chỉ có thể tới level n (2 <= n <= 5) và nếu vượt qua level (n - 1). Màn hình hiển thị game sau mỗi level:
    + Với các màn trước level 5: Nếu thắng, sẽ có 3 nút reload, next và menu. Ngược lại, nếu thua sẽ chỉ có nút reload và menu.
    + Với level 5: Nếu thua sẽ giống như các level trước đó. Nếu thắng, sẽ có background riêng và xuất hiện nút reload và menu để quay về màn hình chính
        
## 4. Các kỹ thuật lập trình được sử dụng trong chương trình:
- Mảng
- Con trỏ
- Struct & Class
- Các hàm của thư viện SDL2, SDL2_image, SDL2_mixer
## 5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình:

