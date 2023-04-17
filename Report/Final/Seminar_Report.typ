#set document(
    title: "Đồ án kĩ thuật lập trình nhóm 11",
    author: "Nhóm 11 - 22CLC01"
)

#import "style.typ": template
#show: template
 
#include "title.typ"

#include "Thanks.typ"

#pagebreak()

#heading(numbering: none)[Mục lục]
#outline()
#pagebreak()

#heading(numbering: none)[Danh sách hình]
#outline(title: none, target: figure.where(kind: image))
#pagebreak()

#heading(numbering: none)[Danh sách bảng]
#outline(title: none, target: figure.where(kind: table))

#include "Chapter1.typ"

#include "Chapter2.typ"

#include "Chapter3.typ"

#pagebreak()

#bibliography(title: "Tài liệu tham khảo", "ReportBib.yml")
