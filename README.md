# Arduino-Orteza-Activa
Comandarea unei orteze active prin intermediul unei placi de dezvoltare Arduino Uno

Codul a fost folosit in cadrul lucrarii de licenta.

Scopul a fost colectarea valorilor unor semnale inregistrate de 4 pini de intrare a unei placute Arduino. 

Fiecarui pin de intrare i-au fost atribuiti doi pini de iesire care comandau fiecare cate un circuit integrat pentru a pune in functiune o serie de motoare de CC care urmau sa se invarta in sens orar sau antiorar.

Cand semnalul de intrare crestea sau scadea sub doua praguri predefinite, un pin de iesire transmitea informatia cu privire la sensul de roatie (depasirea tipului de prag - inferior/superior - determina sensul) iar al doilea pin transmitea semnalul de pornire a motoarelor.

Pentru valorile semnalului de intrare aflate intre cele doua praguri, motoarele erau inactive.
