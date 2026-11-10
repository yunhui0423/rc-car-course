[回首頁](../README.md) · [供電與首件測試](05-power.md)

# 每人一套：實際材料與購買連結

不分組，每人一台車、一支遙控器。以下單價是2026-11-09查得的歷史參考價，並非2026-11-10即時報價或庫存保證。下單前核對接頭、已焊排針、馬達電壓與電流。先完成一套首件再批量採購；沒有實測過這些商品組合。

| 商品 | 每人 | 10人 | 單價NT$ | 注意 |
|---|---:|---:|---:|---|
| [Arduino Nano V3.0 ATmega328P](https://www.jmaker.com.tw/products/arduino-nano) | 1片 | 10片 | 165 | 確認已焊排針與USB接頭 |
| [Uno R3 CH340G＋ATmega328P](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=37512) | 1片 | 10片 | 230 | 非Uno R4 |
| [nRF24L01+普通PCB天線模組 95255](https://www.100y.com.tw/product/95255) | 2片 | 20片 | 80 | 20片需先詢貨；不買裸IC或PA+LNA版 |
| [AMS1117-3.3V電源模組 95467](https://www.100y.com.tw/product/95467) | 2片 | 20片 | 20 | 固定3.3V輸出；到貨量測確認 |
| [TB6612FNG直控雙馬達驅動板](https://jin-hua.com.tw/page/product/show.aspx?kind=12&lang=TW&num=41498) | 1片 | 10片 | 100 | 須有PWMA/PWMB/STBY；確認排針已焊 |
| [2WD智能小車底盤套件](https://jin-hua.com.tw/page/product/show.aspx?kind=3312&lang=TW&num=32270) | 1套 | 10套 | 210 | 含2馬達、2輪、萬向輪、底板、支架螺絲、電池盒與開關；確認4AA盒 |
| [雙軸按鍵搖桿JoyStick](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=13034) | 1片 | 10片 | 40 | X/Y/SW；依絲印接線 |
| [400孔麵包板](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=11934) | 1片 | 10片 | 40 | 遙控端邏輯接線用 |
| [ADIO-SCREW Uno端子台擴充板](https://shop.cpu.com.tw/product/46603/info/) | 1套 | 10套 | 295 | 邏輯接線；不可把馬達電流引入Arduino電源軌 |
| [公對母杜邦線20cm／40條](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=28985) | 1包 | 10包 | 35 | 只走訊號／低電流邏輯供電 |
| [公對公杜邦線20cm／40條](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=28983) | 1包 | 10包 | 35 | 只走訊號／低電流邏輯供電 |
| [USB A-Mini5P資料線75cm](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=17217) | 1條 | 10條 | 25 | 確認Nano實際接頭；若買到Micro/Type-C應換對應線 |
| [USB A-B資料線1.8m](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=17071) | 1條 | 10條 | 80 | 上傳與USB供電；成品可換短線 |
| [LADDA AA 1.2V 2450mAh／4入](https://www.ikea.com.tw/zh/products/electronics/power-supply-and-charging/ladda-art-90506528) | 1包 | 10包 | 349 | 每人4顆；不可用14500鋰電池代替 |

上表每人1,804元／10人18,040元，**不是完整活動總價**，不含下列補充零件、USB行動電源、共用工具、備品、焊接加工及運費。不要再沿用舊估價清單的26,705元當本版總額。

## 全班補充零件（含少量備品）

| 品名 | 10人購買量 | 連結／貨號 | 歷史參考價 |
|---|---|---|---|
| 100uF/16V直插電解電容 | 3包，共30顆 | [今華16V系列](https://jin-hua.com.tw/page/product/p02.aspx?kind=2772)，2000200004387 | 10元/10顆 |
| 0.1uF/50V直插陶瓷，104 | 5包，共50顆 | [今華陶瓷電容](https://jin-hua.com.tw/page/product/p02.aspx?kind=178)，2000200010562 | 10元/10顆 |
| 470uF/16V直插電解電容 | 2包，共20顆 | [今華商品](https://jin-hua.com.tw/page/product/show.aspx?kind=2772&lang=TW&num=7154) | 20元/10顆 |
| 10kΩ/¼W電阻 | 2包，共20支 | [今華商品](https://jin-hua.com.tw/page/product/show.aspx?lang=TW&num=4717) | 10元/10支 |
| 22AWG紅／黑多股電線 | 各5公尺 | 電子材料行依規格購買 | 詢價 |
| 2.54mm洞洞板約5×7cm | 10片 | 焊接驅動板與馬達電源端子 | 詢價 |
| 螺絲端子2P（板端間距配洞洞板） | 每人至少3組，共30組 | 用於VM與兩馬達；選可承受實測電流的型號 | 詢價 |
| 絕緣熱縮套2mm／3mm | 各1包 | 焊點絕緣 | 詢價 |
| 束帶、泡棉雙面膠、絕緣墊 | 各1包／卷 | 板卡與線材固定 | 詢價 |

## 電源與工具

每人需要兩個5V USB電源：Nano端一個、Uno端一個。可自備經實測可用的行動電源；選購例為[Xiaomi 10000口袋版](https://www.mi.com/tw/product/xiaomi-power-bank-10000mah-integrated-cable/)，2026-11-09官網列表參考549元/個，20個10,980元。啟用低電流模式仍要確認定時退出、自動關機與完整課程供電；不能只看到「低電流」就保證整堂穩定。

AA充電器可全班共用3台[IKEA STENKOL](https://www.ikea.com.tw/zh/products/electronics/power-supply-and-charging/stenkol-art-10506527)，歷史參考199元/台，共597元。40顆AA需分批課前充電。

教師另準備電表、可限流直流電源、螺絲起子、斜口鉗、剝線工具、焊台與抽煙設備。未計入個人材料價；已有可借用。

## 到貨與焊接

Nano與TB6612排針、馬達線、馬達0.1uF電容及洞洞板由助教預先焊好。VM與馬達主電流使用焊線／端子，不經麵包板或Arduino 5V軌；ADIO-SCREW只改善Uno訊號接線，不能取代馬達供電載板。底盤附四顆AA盒且開關規格合用時，不重複買。

AMS1117取代舊的RF插座穩壓轉接板：Arduino 5V→IN，3.3V OUT→RF VCC，GND共地，SPI照原接線。不得買成5V輸出模組或TTL串口轉接板。原始購物頁若描述互相矛盾，以實際料號與量測確認為準。
