# IM920
無線モジュール IM920 をArduinoで扱うためのライブラリ。

## 注意

- 正しくプログラムが書かれており、正しくシリアル通信が成り立っていることを前提とする

- 実装されていない機能あり

- 動作確認なし

## コンストラクタ

### IM920(uint8_t busy_pin)

BUSYピンが接続されているピン番号を設定。

### void setWritable(boolean status);

設定パラメータの書き込み許可・禁止を設定。

trueで許可、falseで禁止。

### uint16_t readID()

固有IDを取得。

### void setNodeNum(uint8_t nodeNum)

ノード番号を設定。ユニークな番号でなくてもよい。

### uint8_t readNodeNum()

設定されているノード番号を取得。

### void setTxID(uint16_t id)

通信対象とする送信モジュールのIDを登録。

### uint16_t* readTxID()

登録されている送信モジュールIDを取得。未実装。

### void eraseTxID()

登録されている全ての受信IDを消去。

### void setCH(uint8_t ch)

無線通信チャンネルを設定。1から15を指定可。

対向する無線モジュールと同じ通信チャネルを使用すること。

### uint8_t readCH()

設定されている無線通信チャンネルを取得。

### void sendData(uint8_t* data, size_t len)

データを送信。lenに長さを指定すること。

### uint8_t readRSSI()

現在のRSSI値（信号強度レベル）を取得。

### void setPower(uint8_t pwr)

送信電力を設定。

- 1 : -10 dBm
- 2 : 0 dBm
- 3 : 10 dBm

### uint8_t readPower()

送信電力を取得。

### void setRate(uint8_t rate)

無線通信速度を設定。

- 1 : 高速通信モード（50kbps）
- 2 : 長距離モード（1.25kbps）

### uint8_t readRate()

無線通信速度を取得。

### void setBaud(uint8_t baud)

ボーレートを設定。未実装。

### void setSleep(boolean status)

スリープ状態を設定。trueでスリープ、falseでスリープ解除。

### void reboot()

ソフトウェアリセットする。

### void reset()

パラメータを工場出荷状態にリセット