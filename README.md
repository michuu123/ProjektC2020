# SFML 3D engine
Głównym założeniem projektu jest stworzenie w bibliotece SFML (bibliotece umożliwiającej proste działania na obiektach 2D) programu umożliwiającego użytkownikowi działania na obiektach 3D, takie jak ich tworzenie, przemieszczanie czy nawet kontrolowanie oświetlenia lub animowanie.
## Technologie
- C++
- SFML
## Harmonogram pracy
Rozbudowę projektu planuję rozłożyć na trzy fazy:
- Faza pierwsza obejmuje stworzenie najbardziej podstawowej funkcjonalności, takiej jak tworzenie jednego obiektu wraz z możliwością jego obrotu we wszystkich osiach
- Faza druga obejmuje możliwość tworzenia wielu obiektów, wraz z możliwością kontroli ich położenia względem siebie
- Faza trzecia zakłada dodanie dodatkowej funkcjonalności w postaci manipulacji źródłem światła, oraz/lub innych ciekawych funkcjonalności
## Efekt końcowy
Finalnie program będzie sprawnym silnikiem 3D, którego zasada działania opierać się będzie na rysowaniu dwuwymiarowych wielokątów, których rozmiary, kąty, jak i barwa, a przez to światłocień obliczane będą przez odpowiednie stworzone przeze mnie algorytmy tworząc tym samym złudzenie trójwymiarowości 
## Raport I
Zrealizowana została pierwsza faza, niestety do całkowitego sfinalizowania przyjętych założeń zabrakło możliwości obrotu w osi poziomej. Brak tej funkcjonalności zostanie jednak rozwiązany w przyszłości poprzez całkowitą zmianę mechaniki tworzenia obiektów. Ponad to przy tworzeniu udało mi się zebrać niezbędną wiedzę z zakresu trygonometrii brył przestrzennych, która z pewnością ułatwi realizację kolejnych założeń
## Raport II
Po spostrzeżeniach poczynionych podczas pierwszej fazy projektu silnik uległ całkowitemu przeprogramowaniu i stworzony został na nowo. Tym razem jego mechanika opiera się na sferycznym układzie współrzędnych, co umożliwi obrót tworzonych obiektów we wszystkich osiach. Korzystając z okazji, jaką była konieczność napisania praktycznie całego silnika od początku, program został przepisany na styl obiektowy, co umożliwi płynne przejście do fazy 2, czyli tworzenia wielu obiektów jednocześnie
