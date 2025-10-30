# 🪙 ReservistenCoin (RVC)

**ReservistenCoin (RVC)** ist eine Bitcoin-ähnliche, militärisch inspirierte Kryptowährung, die auf dem **SHA-256 Proof-of-Work Algorithmus** basiert.  
Ziel ist es, Kameradschaft, Ehre und Tradition in das digitale Zeitalter zu übertragen.  
Jeder „Kamerad“ steht für Leistung, Vertrauen und Gemeinschaft — ganz im Sinne unserer Reservistenkultur.

---

## ⚙️ Technische Eigenschaften

| Eigenschaft              | Wert |
|---------------------------|------|
| **Algorithmus**           | SHA-256 (Proof-of-Work) |
| **Block Reward**          | 50 RVC |
| **Halving**               | Alle 210.000 Blöcke |
| **Max. Supply**           | 22.050.000 RVC |
| **Premine**               | 1.050.000 RVC |
| **Coin Unit**             | `Kamerad` |
| **Target Spacing**        | 10 Minuten |
| **Target Timespan**       | 120 Minuten |
| **Difficulty Adjustment** | Dynamisch |
| **Coinbase Maturity**     | 100 + 1 Blöcke |
| **Transaction Confirmations** | 6 |
| **RPC Port**              | 24877 |
| **P2P Port**              | 24878 |
| **Genesis Timestamp**     | “The Times 12/10/2025 — Veterans stand together for peace and freedom.” |

---

## 🧩 Projektstruktur

reservistencoin/
├── src/ # Core-Quellcode
├── share/ # Icons, Grafiken, Ressourcen
├── qt/ # Qt-Wallet (GUI)
├── doc/ # Dokumentation
├── contrib/ # Build-Skripte und Tools
├── README.md # Diese Datei
├── LICENSE # Lizenz (MIT)
└── autogen.sh, configure, makefile.in ...

---

## 🧱 Build-Anleitung (Linux / Windows / Raspberry Pi)

### 🔹 Linux (Ubuntu 22.04 / Debian-basiert)
```bash
sudo apt update
sudo apt install -y build-essential autoconf automake libtool pkg-config \
  libboost-all-dev libevent-dev libminiupnpc-dev libssl-dev \
  qtbase5-dev qttools5-dev-tools git

git clone https://github.com/reservistencoin/reservistencoin.git
cd reservistencoin
./autogen.sh
./configure
make -j$(nproc)

---

🌍 Netzwerk & Node

| Node-Typ         | Host / IP                  | Beschreibung |
| ---------------- | -------------------------- | ------------ |
| **Main Seed**    | seed1.reservistencoin.de   | Haupt-Node   |
| **Backup Seed**  | seed2.reservistencoin.de   | Fallback     |
| **Testnet Seed** | testnet.reservistencoin.de | Testnetzwerk |

---

💎 Wallets & Explorer

| Tool                                       | Beschreibung                                                       | Status        |
| ------------------------------------------ | ------------------------------------------------------------------ | ------------- |
| **reservistencoin-qt**                     | Desktop-Wallet mit GUI                                             | ✅             |
| **reservistencoind / reservistencoin-cli** | Fullnode + CLI                                                     | ✅             |
| **Block Explorer**                         | [explorer.reservistencoin.de](https://explorer.reservistencoin.de) | 🛠️ In Arbeit |
| **Webwallet / Faucet**                     | [wallet.reservistencoin.de](https://wallet.reservistencoin.de)     | 🛠️ Geplant   |

---

⛏️ Mining
CPU-Mining (Testnet)
./reservistencoin-cli generatetoaddress 1 <deineRVCAdresse>

ASIC/Pool-Mining

Verbinde dich mit einem öffentlichen Pool (z. B.):

stratum+tcp://pool.reservistencoin.de:3333

---

🪙 Block Belohnungen (Reward Schedule)


| Epoche | Blockhöhe         | Belohnung (RVC) |
| ------ | ----------------- | --------------- |
| 1      | 0 – 209,999       | 50              |
| 2      | 210,000 – 419,999 | 25              |
| 3      | 420,000 – 629,999 | 12.5            |
| 4      | usw.              | ...             |

Letzter Block mit Reward: ca. Block 6,930,000 (~131 Jahre Laufzeit)

---

🔒 Sicherheit

SHA-256 Hashing wie Bitcoin

Coinbase Maturity: 100 + 1 Blöcke

Netzwerk validiert automatisch Difficulty & Timestamp

Kein zentraler Einfluss, dezentrales Peer-to-Peer-System

Prüfsummen, Signaturen & Safe RPC-Mechanismen integriert

---

🧭 Projektlinks :

🌐 Website: https://reservistencoin.de

💬 Bitcointalk: (folgt)

🧰 GitHub: https://github.com/reservistencoin/reservistencoin

⚙️ Explorer: https://explorer.reservistencoin.de

💦 Faucet: (in Planung)

---

📜 Lizenz

Dieses Projekt steht unter der MIT-Lizenz.
Details siehe LICENSE.

---

🪖 Motto

„Treue, Kameradschaft und Verantwortung – auch in der digitalen Welt.“

