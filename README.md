# Báo cáo bài tập lớn môn Lập trình nâng cao - INT2215_1
- Họ và tên: Phạm Thị Diễm Quỳnh
- MSSV: 21020087
- Tựa game: Rabbit & Carrot

## 1. Cách lấy và chạy chương trình (dành cho hđh Window):
- Bước 1: Download từ github file zip chứa toàn bộ code & thư viện, hình ảnh, âm thanh từ github
- Bước 2: Giải nén, tìm và chạy file `Rabbit & Carrot.exe` để chạy game.

## 2. Mô tả chung về trò chơi, các ý tưởng chính:
- Trò chơi là hành trình thỏ vượt chướng ngại vật đi tìm carrot, được điều khiển bằng 3 phím - [UP], [LEFT], [RIGHT].
- Ý tưởng chính: Bẫy sẽ chỉ hiện ra khi thỏ tới rất gần nó (phản xạ của người chơi không nhanh sẽ không tránh được). Sử dụng dữ liệu từ map tự tạo để tạo độ khó cho game.

## 3. Mô tả các chức năng đã cài đặt

[Video minh họa](https://www.youtube.com/watch?v=uVNvpU1Bqng)

**Mô tả**:  
- Tại Menu nút `start`, `quit` để vào/thoát game.
- Thỏ có thể tiến, lùi, bay và đứng lại trên nền (gạch, ống), rơi tự do nếu đang trên không trung mà ko ấn phím [UP]. 
- Bẫy sẽ hiện khi thỏ đứng gần nơi đặt bẫy, đây cũng là điểm nhấn và là điểm cần xử lý nhiều nhất trong project của em. 
- Mỗi lần vào game từ menu hoặc sang 1 level sẽ có 1 background khác nhau. Nếu dùng reload, background sẽ giữ nguyên như cũ.
- Có âm thanh làm hiệu ứng lúc bay, chạm chướng ngại vật; có nhạc tại Menu, lúc đang chơi game, lúc thắng/thua.
- Game có 5 level. Từ menu vào sẽ vào level 1. Chỉ có thể tới level n (2 <= n <= 5) và nếu vượt qua level (n - 1). Màn hình hiển thị game sau mỗi level:
    + Với các màn trước level 5: Nếu thắng, sẽ có 3 nút reload, next và menu. Ngược lại, nếu thua sẽ chỉ có nút reload và menu.
    + Với level 5: Nếu thua sẽ giống như các level trước đó. Nếu thắng, sẽ có background riêng và xuất hiện nút reload và menu để quay về màn hình chính
        
## 4. Các kỹ thuật lập trình được sử dụng trong chương trình:
### Các kỹ thuật lập trình
- Sử dụng các kiến thức cơ bản đã được dạy như mảng (mảng hằng), xâu (string), hàm rand()...;
- Sử dụng biến const, con trỏ và tham chiếu;
- Sử dụng class, struct, extern,...
### Với thư viện SDL2, SD2_image, SDL2_mixer
- Xử lí sự kiện chuột, bàn phím;
- Sử dụng hàm callback để hiện bẫy khi thỏ lại gần;
- Sử dụng hàm trong các thư viện để tạo hình ảnh, âm thanh cho game.

Ngoài ra, đã hiểu và vận dụng cách chia file và quản lí file cpp, file header;

## 5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình:
### Kết luận và điều tâm đắc
Qua quá trình suy nghĩ ý tưởng, bắt tay vào làm và hoàn thiện project này, em đã củng cố và học thêm được rất nhiều những điều thú vị và mới mẻ trong các thư viện, cách sử dụng hàm, biến trong C++. Em nhận ra được rằng, để làm một project không chỉ cần sự hiểu biết về các hàm, tính năng riêng của từng thư viện mà 1 lập trình viên còn phải biết cách kết hợp chúng và tạo ra các chức năng như mình mong muốn - cũng như cách một đầu bếp biết kết hợp các nguyên liệu để tạo ra một món ăn ngon. Ngoài ra, em nhận thấy việc sử dụng các thư viện khác nhau, các ngôn ngữ lập trình khác nhau đều có thể tạo được những chức năng mình mong muốn, miễn là có sự tư duy và hiểu biết của lập trình viên. Dù trong quá trình code gặp không ít bug và phải debug khá lâu nhưng qua đó em cũng đã dần định hình được cách xác định bug và debug trong 1 project cỡ trung bình/ lớn. Em mong rằng trong quá trình học sau này, em có thể được thầy cô chỉ dẫn nhiều hơn nữa để em khám phá ra thêm những kỹ năng mới và những điều thú vị của lập trình.
### Hướng phát triển game
- Xử lý phần hiện bẫy để hiện từng bẫy thay vì nếu hiện sẽ hiện tất cả bẫy cùng loại;
- Có thể kéo dài và mở rộng map hơn;
- Cân nhắc việc cho người chơi chọn level muốn chơi từ menu;
- Tạo ra nhiều map/level hơn;
- Thêm những bẫy có chuyển động;
