#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (maps.count(val)) return false;
        maps[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!maps.count(val)) return false;

        // 最后一个元素和删除元素交换
        int index = maps[val];
        int last = nums.back();
        nums[index] = last;
        maps[last] = index;

        // 删除nums最后一个元素, 删除maps对应元素
        nums.pop_back();
        maps.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand()%nums.size();
        return nums[randomIndex];
    }

private:
    unordered_map<int, int> maps;
    vector<int> nums;

};



int main () {
    RandomizedSet rs = *new RandomizedSet();
    
}