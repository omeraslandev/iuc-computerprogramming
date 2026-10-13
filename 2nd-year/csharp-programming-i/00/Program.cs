using System;

namespace DersNotlari
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            Console.WriteLine("==== C# DERS NOTLARI MODÜLER İNDEKSİ ====");
            Console.WriteLine("1 - Konsol İşlemleri (Method vs Property)");
            Console.WriteLine("2 - Değişkenler, Scope ve İlklendirme");
            Console.WriteLine("3 - Sabitler (const) ve Kuralları");
            Console.WriteLine("4 - Veri Tipleri ve Default Değerler");
            Console.WriteLine("5 - Tür Dönüşümleri (Ödev: Bilinçli / Bilinçsiz)");
            Console.WriteLine("========================================");
            Console.Write("Çalıştırmak istediğiniz modül numarasını seçiniz (1-5): ");

            string secim = Console.ReadLine();
            Console.Clear();

            switch (secim)
            {
                case "1":
                    KonsolIslemleri.Calistir();
                    break;
                case "2":
                    DegiskenlerVeScope.Calistir();
                    break;
                case "3":
                    SabitlerConst.Calistir();
                    break;
                case "4":
                    VeriTipleriVeVarsayilanDegerler.Calistir();
                    break;
                case "5":
                    TurDonusumleri.Calistir();
                    break;
                default:
                    Console.WriteLine("Geçersiz seçim yapıldı.");
                    break;
            }

            Console.WriteLine("\n\nDevam etmek için bir tuşa basınız...");
            Console.ReadKey();
        }
    }
}