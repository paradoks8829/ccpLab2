#include "lab2.h"

void task2_4() {
    std::vector<int> V;
    std::list<int> L;
    int n;
    std::cout << "Введите размер вектора V (V >= 5): ";
    std::cin >> n;
    std::cout << "Введите " << n << " элементов вектора V: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        V.push_back(x);
    }
    std::cout << "Введите размер списка L (L >= 5): ";
    std::cin >> n;
    std::cout << "Введите " << n << " элементов списка L: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        L.push_back(x);
    }
    auto it = L.begin();
    std::advance(it, 5);
    L.insert(it, V.rbegin(), V.rbegin() + 5);
    std::cout << "Список L после вставки: ";
    for (auto it2 = L.begin(); it2 != L.end(); ++it2) std::cout << *it2 << " ";
    std::cout << std::endl;
}

void task3_9() {
    std::deque<int> D;
    int n;
    std::cout << "Введите размер дека D (D кратен 4): ";
    std::cin >> n;
    std::cout << "Введите " << n << " элементов дека D: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        D.push_back(x);
    }
    std::cout << "Исходный дек D: ";
    for (auto it = D.begin(); it != D.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    auto i = D.begin();
    for (int j = 0; j < n / 4; ++j) {
        i = D.erase(++i);
    }
    std::cout << "Дек D после удаления: ";
    for (auto it = D.begin(); it != D.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
}

void task4_3() {
    std::vector<double> V;
    std::cout << "Введите вещественные числа (конец ввода — не число): ";
    std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), std::back_inserter(V));
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Числа с чётными порядковыми номерами: ";
    int index = 0;
    std::remove_copy_if(V.begin(), V.end(), std::ostream_iterator<double>(std::cout, " "),
        [&index](double) { return (++index % 2) != 0; });
    std::cout << std::endl;
}

void task5_5() {
    std::list<int> L;
    int n;
    std::cout << "Введите размер списка L: ";
    std::cin >> n;
    std::cout << "Введите " << n << " элементов списка L: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        L.push_back(x);
    }
    std::cout << "Исходный список L: ";
    for (auto it = L.begin(); it != L.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    auto first_neg = std::find_if(L.begin(), L.end(), [](int x) { return x < 0; });
    if (first_neg != L.end()) {
        L.insert(++first_neg, 0);
    }
    auto last_pos = std::find_if(L.rbegin(), L.rend(), [](int x) { return x > 0; });
    if (last_pos != L.rend()) {
        L.insert(--last_pos.base(), 0);
    }
    std::cout << "Список L после вставки: ";
    for (auto it = L.begin(); it != L.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
}

void task6_14() {
    std::vector<int> V;
    int n;
    std::cout << "Введите размер вектора V (чётный): ";
    std::cin >> n;
    std::cout << "Введите " << n << " элементов вектора V: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        V.push_back(x);
    }
    std::cout << "Исходный вектор V: ";
    for (auto it = V.begin(); it != V.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    std::vector<int> V0(V.begin() + n / 2, V.end());
    auto min_it = std::min_element(V.begin(), V.end());
    int min_val = *min_it;
    V.clear();
    std::remove_copy_if(V0.begin(), V0.end(), std::back_inserter(V),
        [min_val](int x) { return x < min_val; });
    std::cout << "Вектор V после удаления элементов перед минимальным: ";
    for (auto it = V.begin(); it != V.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
}

void task7_11() {
    std::deque<std::string> D;
    int n;
    std::cout << "Введите количество слов: ";
    std::cin >> n;
    std::cout << "Введите " << n << " английских слов: ";
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        D.push_back(s);
    }
    std::sort(D.begin(), D.end(), [](const std::string& a, const std::string& b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a < b;
    });
    std::cout << "Отсортированный дек D: ";
    for (auto it = D.begin(); it != D.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
}

void task8_1() {
    std::list<int> L;
    int n;
    std::cout << "Введите размер списка L: ";
    std::cin >> n;
    std::cout << "Введите " << n << " элементов списка L: ";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        L.push_back(x);
    }
    std::vector<double> V;
    std::adjacent_difference(L.begin(), L.end(), std::back_inserter(V),
        [](int a, int b) { return (a + b) / 2.0; });
    V.erase(V.begin());
    std::cout << "Вектор V средних арифметических соседних пар: ";
    for (auto it = V.begin(); it != V.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
}

void task9_1() {
    std::vector<int> V0;
    int n0;
    std::cout << "Введите размер вектора V0: ";
    std::cin >> n0;
    std::cout << "Введите " << n0 << " элементов вектора V0: ";
    for (int i = 0; i < n0; ++i) {
        int x;
        std::cin >> x;
        V0.push_back(x);
    }
    std::sort(V0.begin(), V0.end());
    V0.erase(std::unique(V0.begin(), V0.end()), V0.end());
    int N;
    std::cout << "Введите количество векторов N > 0: ";
    std::cin >> N;
    std::vector<std::vector<int>> V(N);
    for (int i = 0; i < N; ++i) {
        int ni;
        std::cout << "Введите размер вектора V" << i + 1 << ": ";
        std::cin >> ni;
        std::cout << "Введите " << ni << " элементов вектора V" << i + 1 << ": ";
        for (int j = 0; j < ni; ++j) {
            int x;
            std::cin >> x;
            V[i].push_back(x);
        }
        std::sort(V[i].begin(), V[i].end());
        V[i].erase(std::unique(V[i].begin(), V[i].end()), V[i].end());
    }
    int count = 0;
    for (auto it = V.begin(); it != V.end(); ++it) {
        if (std::includes(it->begin(), it->end(), V0.begin(), V0.end())) {
            ++count;
        }
    }
    std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;
}

void task10_2() {
    std::vector<std::string> V;
    int n;
    std::cout << "Введите количество слов: ";
    std::cin >> n;
    std::cout << "Введите " << n << " английских слов заглавными буквами: ";
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        V.push_back(s);
    }
    std::map<char, int> M;
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[(*it)[0]] += it->size();
    }
    std::cout << "Суммарная длина слов по начальным буквам:" << std::endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << it->second << std::endl;
    }
}