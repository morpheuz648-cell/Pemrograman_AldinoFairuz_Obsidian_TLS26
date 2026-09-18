# Pemrograman_AldinoFairuz_Obsidian_TLS26

graph TD
    Start((Mulai Loop)) --> Cond1{Jumlah astronot > 1?}
    Cond1 -- Tidak --> Finish((Selesai: Pemenang Ditemukan))
    Cond1 -- Ya --> Calc[Hitung indeks: hapus = <br> %28pos + K - 1%29 % sisa_astronot]
    
    Calc --> UpdateData[Ambil ID, Hapus dari list, <br>Update pos = hapus]
    UpdateData --> Cond2{Apakah ID genap?}
    
    Cond2 -- Ya --> K_Plus[K = K + 2]
    Cond2 -- Tidak --> K_Minus[K = K - 1]
    
    K_Minus --> Cond3{Apakah K < 2?}
    Cond3 -- Ya --> K_Reset[K = 2]
    Cond3 -- Tidak --> LoopBack
    
    K_Reset --> LoopBack
    K_Plus --> LoopBack[Kembali ke awal loop]
    
    LoopBack --> Cond1
