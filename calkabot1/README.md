# Mini-Sumo
First really project by CałkaCompany+

Oznaczenia wyjść i wejść w kodzie:

| numer wyjścia | arduino | zmienna w kodzie  |                 opis            |
| ------------  |---------| ----------------  | ------------------------------  |
|       1       |  PWM/D11|      `floorFR`    |    Czujnik podłoża prawy tylny  |
|       2       |    D13  |      `floorBR`    |   Czujnik podłoża prawy przedni |
|      31       |  D10    |     `floorFL`     |   Czujnik podłoża lewy tylny    |
|      32       |    D12  |     `floorBL`     |  Czujnik podłoża lewy przedni   |
|               |         |                   |                                 |
|    3\5\21     |   GND   |         `-`       |           Uziemienie            |
|      4\6      |   VCC   |         `-`       |           Zasilanie             |
|               |         |                   |                                 |
|      ?        |    D12  |       `AIN1`      |       Prawy silnik w tył        |\
|       ?       |    D13  |       `AIN2`      |      Prawy silnik w przód       | \    Patrząc na
|      ?        |    D10  |       `BIN1`      |       Lewy silnik  w tył        | /      mordke!
|       ?       |    D11  |       `BIN2`      |      Lewy silnik  w przód       |/
|               |         |                   |                                 |
|      ?        |    D3   |      `sensorFL`   | Czujnik odległości lewy przedni |
|      ?        |    D2   |     `sensorFR`    | Czujnik odległości prawy przedni|
|      ?        |    D0   |     `sensorF`     |   Czujnik odległości przedni    |
|      ?        |    D1   |     `sensorBL`    | Czujnik odległości prawy tylny  |
|      ?        |    D7   |     `sensorB`     |   Czujnik odległości tylni      |
|      ?        |    D4   |     `sensorBR`    |  Czujnik odległości prawy tylni |
