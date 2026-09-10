>> "w" (write)
- Dosya yazmak icin acilir.
- Dosyadan okuma yapilmaz.
- Dosyanin onceden var olması zorunlu degildir.
- Dosya yok ise verilen isimde bir dosya olusturulur.
- Dosya var ise dosya sifirlanir.
- Var olan bir dosyayi bu modda acmak, var olan
  dosyadaki bilgilerin kaybedilmesine neden olur.

>> "w+" (write+)
- Dosyayi hem yazma hem de okuma icin acar.
- Dosyanin var olması zorunlu degildir.
- Dosya yok ise verilen isimde bir dosya olusturulur.
- Dosya var ise dosya sifirlanir.
- Var olan bir dosyayi bu modda acmak, var olan
  dosyadaki bilgilerin kaybedilmesine neden olur.

---

>> "r" (read)
- Dosya okumak icin acilir.
- Dosyaya yazilamaz.
- Dosya yok ise acilamaz.

>> "r+" (read+)
- Dosya hem okuma hem yazma icin acilir.
- Dosya yok ise acilamaz.

---

>> "a" (append)
- Dosya sona ekleme icin acilir.
- Dosyadan okuma yapılamaz.
- Dosyanin var olmasi zorunlu degildir.
- Dosya yok ise verilen isimde bir dosya olusturulur.
- Dosya var ise dosya sifirlanmaz.

>> "a+" (append+)
- Dosyayi sonuna ekleme ve dosyadan okuma icin acar.
- Dosyanin var olması zorunlu degildir.
- Dosya yok ise verilen isimde bir dosya olusturulur.
- Dosya var ise dosya sifirlanmaz.