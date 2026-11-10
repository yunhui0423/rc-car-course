# 範例程式

[回首頁](../README.md) · [安裝與上傳](../docs/09-setup.md) · [接線](../docs/04-wiring.md)

| 階段 | Nano | Uno |
|---|---|---|
| 第1堂 | [PingTx](PingTx/PingTx.ino) | [PingRx](PingRx/PingRx.ino) |
| 第2堂 | 不使用 | [Bench](Bench/Bench.ino) |
| 第3堂 | [Remote](Remote/Remote.ino) | [Car](Car/Car.ino) |

先Verify，再Upload。個人兩端VEHICLE_ID相同，每人車號不同；支援1至10。Car馬達預設停用，Bench只作架空測試。

第3堂回報前次處理的序號與PWM，不是即時速度。斷訊、換向鎖定、回中解鎖等流程見[第三堂](../docs/03-integration.md)。
