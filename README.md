# 🇹🇷 Türkiye Yerel Seçimleri 2023 Sonuç Analiz Programı 📜

Bu proje, Türkiye Yerel Seçimleri sonuçlarını analiz etmek, sorgulamak ve raporlamak amacıyla C++ ile geliştirilmiş bir konsol uygulamasıdır. 

Uygulama, geçmişte kod içerisine gömülü (hardcoded) olan tüm seçim verilerini harici bir veritabanı dosyasından (`election_data.txt`) dinamik olarak okur, belleğe yükler ve kullanıcıya gelişmiş sorgu seçenekleri sunar. Aynı zamanda programın çalışma esnasındaki kullanıcı aktivitelerini `election.txt` dosyasına loglar.

---

## ✨ Özellikler

Program çalıştırıldığında kullanıcıya aşağıdaki analiz ve sorgulama seçeneklerini sunar:

1. **🏛️ İl Belediye Başkanı Sorgulama:** Girilen plaka koduna (1-81) göre seçilen ilin belediye başkanını gösterir.
2. **🎉 Kazanan Parti Sorgulama:** Girilen plaka koduna göre o ilde seçimi kazanan siyasi partiyi gösterir.
3. **📊 Tüm Partilerin Oy Oranları:** İlgili ilde seçime giren tüm partilerin aldıkları oy oranlarını listeler.
4. **🔍 Parti Bazlı İl Listeleme:** Belirtilen bir partinin (örn: CHP, AKP, DEM, MHP vb.) Türkiye genelinde kazandığı tüm illeri plaka kodlarıyla birlikte listeler.
5. **📈 Türkiye Geneli Özet İstatistik Raporu:**
   - Hangi partinin Türkiye genelinde toplam kaç belediye kazandığını gösteren dağılım tablosu.
   - Türkiye genelinde tek bir ilde elde edilen rekor (en yüksek) oy oranına sahip belediyeyi, kazanan partiyi ve oy oranını raporlar.
6. **📝 İşlem Günlüğü (Loglama):** Kullanıcının yaptığı tüm aramalar ve programın yanıtları, her çalıştırmada sıfırlanan `election.txt` dosyasına kaydedilir.

---

## 📂 Dosya Yapısı ve Sınıf Hiyerarşisi

Proje nesne yönelimli programlama (OOP) prensiplerine uygun olarak tasarlanmıştır:

- **[main.cpp](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/main.cpp):** Programın ana döngüsünü yönetir, verileri başlatır ve menü yönlendirmelerini yapar.
- **[Cities.h](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Cities.h) / [Cities.cpp](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Cities.cpp):** Seçim verilerini (`CityData` ve `PartyVote` yapıları) temsil eder. Verileri dosyadan yükleyen (`loadElectionData`) ve genel raporları oluşturan statik fonksiyonları barındırır.
- **[Election.h](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Election.h) / [Election.cpp](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Election.cpp):** Menü gösterimi, kullanıcı girdi doğrulamaları (1-6) ve plaka kodu kontrolü (1-81) işlemlerini üstlenir.
- **[Mayority.h](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Mayority.h) / [Mayority.cpp](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Mayority.cpp):** Seçilen ilin belediye başkanı verisini bulup ekrana yazdırır.
- **[WinnerParty.h](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/WinnerParty.h) / [WinnerParty.cpp](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/WinnerParty.cpp):** Seçilen ilin kazanan partisini bulup ekrana yazdırır.
- **[Percentage.h](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Percentage.h) / [Percentage.cpp](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/Percentage.cpp):** Seçilen ile ait tüm partilerin oy dağılım yüzdelerini ekrana yazdırır.
- **[election_data.txt](file:///c:/Users/Acer/Downloads/Result-of-Turkey-Election-2023/election_data.txt):** Tüm illerin güncel seçim verilerini tutan noktalı virgül (`;`) ile ayrılmış veritabanı dosyasıdır.

---

## 💾 Veritabanı Formatı (`election_data.txt`)

Veri dosyası her satırda bir ili temsil edecek şekilde şu şablonla yapılandırılmıştır:
`[Plaka No];[İl Adı];[Belediye Başkanı];[Kazanan Parti];[Parti1]:[Oy Oranı],[Parti2]:[Oy Oranı]...`

**Örnek Satırlar:**
```text
1;Adana;Zeydan Karalar;CHP;CHP:%46.57,AKP:%37.43,DEM:%5.60
6;Ankara;Mansur Yavas;CHP;CHP:%60.44,AKP:%31.68,YRP:%3.13
34;Istanbul;Ekrem Imamoglu;CHP;CHP:%51.14,AKP:%39.59,YRP:%2.61
```

---

## 🚀 Derleme ve Çalıştırma

Programı standart bir C++ derleyicisi (örneğin GCC) kullanarak terminal üzerinden şu komutla derleyebilirsiniz:

```bash
g++ main.cpp Election.cpp Cities.cpp WinnerParty.cpp Percentage.cpp Mayority.cpp -o election_app
```

Derleme tamamlandıktan sonra programı çalıştırmak için:

```bash
./election_app
```

> **Not:** Uygulamanın verileri başarıyla okuyabilmesi için `election_data.txt` dosyasının, derlenen çalıştırılabilir program (`election_app`) ile **aynı dizinde** bulunması gerekmektedir.
