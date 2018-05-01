# Szachy_Cpp

INSTRUKCJA

1. GRA KLASYCZNA

Szachownica składa się z 64 pól. Drugi rząd od strony gracza mieści osiem pionów; rząd najbliższy graczowi zawiera figury rozmiszczone wg następujących zasad:
- wieże w narożnikach planszy;
- skoczki sąsiadują z wieżami od strony wewnętrznej;
- gońce obok skoczków po ich wewnętrznej stronie;
- hetman na jednym ze środkowych pól – tym, które ma kolor zgodny z kolorem gracza (np.: biały hetman na białym polu)
- król - ostanie wolne pole w dolnym rzędzie, obok hetmana.

Grę rozpoczyna zawodnik z białymi bierkami. Grę kończy zmatowanie jednego z króli, remis lub rezygnacja gracza z dalszej gry. 

Podstawowe ruchy bierek:
- król - jedno pole w poziomie, pionie lub na ukos. Najwyżej raz w grze każdy z króli może wykonać roszadę.
- wieża - o dowolną liczbę wolnych pól w poziomie i pionie; porusza się także podczas roszady,
- goniec - o dowolną liczbę wolnych pól po przekątnych,
- hetman - o dowolną liczbę wolnych pól w poziomie, pionie i na ukos (łączy zatem w sobie ruchy wieży i gońca),
- skoczek - dwa pola w jednym kierunku oraz jeden w bok, lub jeden do przodu i dwa w bok. Ruch skoczka nie jest blokowany przez inne bierki.
- pion - może poruszyć się o jedno pole naprzód, o ile jest ono wolne. Jeżeli nie wykonano danym pionem posunięcia, to w pierwszym ruchu ma on możliwość wykonania ruchu o dwa pola naprzód, o ile oba z nich są wolne. Pion nie może ruszać się do tyłu.
Piony są jedynymi bierkami, które biją inaczej niż się poruszają. Mogą one zbić wrogą bierkę z pól na ukos przed nimi, wykonywac bicie w przelocie (zbicie pionka przeciwnika, gdy ten wyrusza ze swojego obozu dwa pola do przodu, a nasz pionek zajmuje czwartą lub piątą linię i jest to zarazem sąsiednia pionowa linia pionka zbijanego. Bicie w przelocie możemy wykonać tylko bezpośrednio po posunięciu przeciwnika.) oraz mają możliwość promocji (gdy pion osiągnie ósmy rząd,jest promowany (zamieniany) na hetmana, wieżę, gońca lub skoczka tego samego koloru; wybór zależy od gracza).

Roszada (król idzie o dwa pola w lewo lub prawo, a wieża przeskakuje króla) wymaga spałnienia następujących warunków:
- pomiędzy królem a wieżą nie znajdują się żadne bierki;
- ani król, ani wieża nie wykonywały w partii żadnych posunięć;
- król nie jest pod szachem;
- król nie przeskoczy przez pole szachowane, ani nie stanie pod szachem po zakończeniu roszady.

2. SZACHY HEKSAGONALNE // CHYBA O TO CHODZIŁO W BACKLOG: "baza różnych kształtów planszy (ile pól, jak opisywać położenie pionka na danej planszy, jeśli jest wielokątem, określenie sposobu poruszania się)" ?

Szachownica ma 91 pól w trzech kolorach: ciemnym, jasnym i pośrednim (pól pośrednich jest 31, pól jasnych i ciemnych po 30). Na szachownicy jest 11 pionowych rzędów (kolumn), mają one oznaczenia od A do L (J nie jest używane). Skośne rzędy na szachownicy są ponumerowane od 1 do 11. Rząd F dzieli szachownicę na dwie połowy; lewą hetmana (rzędy od A do E) oraz prawą króla (rzędy od G do L). Zawodnicy mają do dyspozycji dwa komplety figur, każdy po 18 figur: 1 król, 1 hetman (królowa), 2 wieże, 3 gońce, 2 skoczki i 9 pionów. Grę rozpoczyna zawodnik z białymi figurami. Dwoma kluczowymi zasadami są: 
1. Nie można bić króla.
2. Bicie figury polega na zdjęciu z szachownicy figury bitej i postawieniu na jej miejscu figury bijącej.

Dla poszczególnych figur mozliwe są następujące sposoby prouszania się:
- wieża- po linach prostych, po polach które przylegają do siebie bokami,
- goniec- po polach tego samego koloru, po linach prostych. Goniec środkowy może się poruszać po 31 polach, a pozostałe gońce po 30 polach,
- hetman- może poruszać się w 12 kierunkach (jego ruchy są połaczeniem ruchów wieży oraz gońca),
- król- może poruszać się tak jak hetman, ale wyłacznie o jedno pole,
- skoczek- dwa pola w jednym kierunku oraz jeden w bok, lub jeden do przodu i dwa w bok,
- pion- do przodu i tylko o jedno pole, bicie może wykonywać tylko w bok.

Pozostałe zasady ruchów są identyczne jak w przypadku gry klasycznej. 

3. SZACHY BIZANTYJSKIE // ~"OKRĄGŁE", KOMENTARZ JAK WYŻEJ

Gra rozgrywana jest na planszy w kształcie koła składającej się z 64 pól ułożonych w 16 rzędach (po 4 pola) tworzących cztery pierścienie pól wokół środka planszy. Ustawienie bierek jest takie samo jak w klasycznej wersji gry za wyjatkiem królów i hetmanów, które są zamienione ze sobą miejscami. Ruchy królów, wież oraz skoczków są identyczne jak w klasycznej wersji gry. Hetman może poruszać się o jedno pole po przekątnych. Goniec może wykonywać ruchy o dwa pola po przekątnych. Figury mogą poruszać się po planszy w tył albo w przód. Istotnym jest, że wieża nie może okrążyć całej planszy i w tym samych ruchu wrócić na pole, z którego wyszła. Pionki mają mozliwośc poruszania się tylko do przodu i nie mogą zostać awansowane. Żadna bierka nie może ani wejść na środkowe pole, ani przez nie przejść. Zwycięzcą zostaje gracz, który zmatuje króla przeciwnika, doprowadzi go do sytuacji patowej, lub też zbije wszystkie pionki przeciwnika. W sytuacji jednak, gdy w kolejnym ruchu gracz, któremu został wyłącznie król, może doprowadzić do takiej samej sytuacji przeciwnika, wówczas mamy do czynienia z remisem. 


4. WYBIJANKA //? OPCJONALNIE

Róznica pomiędzy wybijanką a klasyczną wersją gry polega na tym, że bicie jest obowiązkowe. Co więcej, zbicie króla nie kończy gry. Zwycięzcą zostaje osoba, która pierwsza straci wszystkie bierki. 

5. SZACHY CAPABLANKI (WERSJA 80 I 100 PÓL)

Ta stworzona przez trzeciego mistrza świata wersja gry została wprowadzona dla urozmaicenia pojedynków szachowych poprzez wprowadzenie dwóch nowych figur:
- arcybiskupa - figury stojącej na C1 i C8 i poruszającej się jak goniec i skoczek,
- kanclerza, figury stojącej na H1 i H8 i poruszającejsię jak wieża i skoczek.

Pozostałe zasady są identyczne jak w grze klasycznej.

6. SZACHY DLA 3 OSÓB

Do tej wersji gry używa się szachownicy w kształcie sześciokata foremnego podzielonej na 96 pól (trzy strefy dla trzech graczy po 32 pola). Zasady są identyczne jak w grze klasycznej. Różnica polega na zakończeniu gry; zwycięzcą zostaje ten z graczy, który zadał mata. Gracz, który otrzymał mata oraz gracz, który (czynnie lub biernie) uczestniczył w zadaniu mata przegrywają. 

7. SZACHY DLA 4 OSÓB

Gra rozgrywana jest na szachownicy zawirającej 160 pól. W trakcie gry każdy z graczy wykonuje po jednym ruchu zgodnie z ruchem wskazówek zegara. Dla lepszej organizacji, figury zmatowanego zawodnika zabierane są z szachownicy. Pozostałe zasady są identyczne jak w grze klasycznej.

8. SZACHY LOSOWE (FISCHERA) //? OPCJONALNIE

Stworzone przez 11 mistrza świata Bobbiego Fischera szachy charakteryzują się tym, że figury są rozmieszczone na pierwszej i ósmej linii (co daje 960 możliwości). Pionki rozmieszczone są jak w wersji klasycznej. Róznica pomiędzy tą wersją gry a szchami klasycznymi opiera sie na róznicy w ustawieniu figur oraz w zasadach wykonania roszady (zasady jak w klasycznych szachach ale szerzej interpretowane):
- po roszadzie ustawienie zawsze jest takie, jak w klasycznych szachach, czyli niezależnie od tego, gdzie król i wieża stały przed roszadą,
- ani król, ani roszująca z nim wieża nie mogły wykonać uprzednio żadnego ruchu,
- król nie może znaleźć się pod szachem,
- pomiędzy królem a wieżą nie może znaleźć się żadna bierka (to samo dotyczy pól końcowych z wyjątkiem sytuacji, gdy na polu końcowym stoi druga z roszujących bierek),
- pod szachem nie może być żadne z pól, przez które król przechodzi roszując.

Zasady rozmieszczenia bierek:

- król musi znajdować się na dowolnym polu między dwiema Wieżami,
- gońce stoją na polach przeciwnego koloru,
- obaj gracze dysponują identycznymi ustawieniem figur.
