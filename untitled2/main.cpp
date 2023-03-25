#include <iostream>
#include <vector>
#include <set>
#include <cinttypes>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned max_ri = 0;
    unsigned int N;
    std::cin >> N;

    std::vector<unsigned int> c;
    for (unsigned int i = 0; i < N; i++){
        unsigned tmp;
        std::cin >> tmp;
        c.push_back(tmp);
    }

    std::vector<unsigned int> r;
    for (unsigned int i = 0; i < N; i++){
        unsigned tmp;
        std::cin >> tmp;
        r.push_back(tmp);
        if (tmp > max_ri){
            max_ri = tmp + 1;
        }
    }
    if (max_ri <= 1){
        std::cout << 0;
        return 0;
    }

    std::set<unsigned> set_ri[max_ri];
    for (int i = 0; i < max_ri; ++i){
        set_ri[i].clear();
    }
    for (unsigned i = 0; i < r.size(); i++){
        set_ri[r[i]].insert(c[i]);
    }

    unsigned int K;
    std::cin >> K;

    std::vector<unsigned int> s;
    for (unsigned int i = 0; i < K; i++){
        unsigned tmp;
        std::cin >> tmp;
        s.push_back(tmp);
    }

    if (N <= 1){
        unsigned result = 0;
        std::cout << result;
        return 0;
    }
    unsigned T = 0;
    for (unsigned i = 0; i < K; i++){
        unsigned pos = 0;
        for (unsigned j = 0; j < max_ri; j++){
            auto found = set_ri[j].find(s[i]);
            if (found != set_ri[j].end()){
                pos = j;
                break;
            }
        }
        static unsigned prev_pos;
        if (i != 0){
            if (prev_pos != pos){
                T++;
            }
        }
        prev_pos = pos;
    }

    std::cout << T;

    return 0;
}
