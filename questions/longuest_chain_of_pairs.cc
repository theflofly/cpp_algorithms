// adaptation of the longuest increasing subsequence algorithm to be used with pairs

#include<iostream>
#include<vector>
#include<set>
#include <math.h>
#include <algorithm>

using namespace std;

// lower_bound = binary search
int BinarySearch(vector<int> array, int val) {
    vector<int>::iterator i = std::lower_bound(array.begin(), array.end(), val);
    if (i != array.end() && !(val < *i))
        return static_cast<int>(distance(array.begin(), i));
    else
        return -1;
}

int main() {
    
    vector<pair<int, int>> input_pairs = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 6},
        {5, 7},
        {6, 7},
        {7, 8},
        {8, 9},
        {10, 14}
    };
    
    // sort the pair (x, y) on the y value
    sort(input_pairs.begin(), input_pairs.end(),
        [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    
    vector<int> size;
    vector<int> last;
    // contains the last vector's index of the predecessor element
    vector<int> predecessor;
    
    for (int i = 0; i < input_pairs.size(); i++) {
        
        // current pair that we are adding to the sequences
        pair<int, int> current_pair = input_pairs[i];
        
        // index of the x element of the pair
        int i_x = BinarySearch(last, current_pair.first);
        
        // index of the y element of the pair
        int i_y = BinarySearch(last, current_pair.second);
        
        
        // first time that we insert a pair with these (x, y)
        if (i_x == -1 && i_y == -1) {
            size.push_back(1);
            last.push_back(current_pair.second);
            predecessor.push_back(-1 * current_pair.first);
            
        // there is already a pair ending with x to which we can concatenate the current pair
        } else if (i_x != -1 && i_y == -1) {
            size.push_back(size[i_x] + 1);
            last.push_back(current_pair.second);
            predecessor.push_back(i_x);
            
        // there is no pair ending with x to which we can concatenate the current pair
        // but the y of the current pair already ends a sequence
        } else if ((i_x == -1 && i_y != -1)) {
            // we discard the current pair because if we can't concatenate it, it means that its size is at most 1
            // and there is already a chain ending with y with a size of at least 1, so the current pair is ignored
            
        // tricky case where we can concatenate the x to a chain, but there is already a chain ending with y
        // in that case we keep the best choice
        } else if ((i_x != -1 && i_y != -1)) {
            int futur_x_size = size[i_x] + 1;
            int current_y_size = size[i_y];
            
            // is the concatenation of the current pair to a chain longer than
            // the sequence ending with y? if yes, we discard the sequence ending with y
            if (futur_x_size > current_y_size) {
                size[i_y] = futur_x_size;
                predecessor[i_y] = i_x;
            } // else we discard the current pair
        }
        
    }
    
    // we find the max size sequence
    int max_size = -1;
    int max_index = -1;
    for (int i = 0; i < size.size(); ++i) {
        if (size[i] > max_size) {
            max_size = size[i];
            max_index = i;
        }
    }
    
    cout << "The longuest chain has " << max_size << " items" << endl;
    set<int> unique_items;
    
    while (true) {
        
        unique_items.insert(last[max_index]);
        
        if (predecessor[max_index] < 0) {
            unique_items.insert(predecessor[max_index] * -1);
            break;
        }
        
        max_index = predecessor[max_index];
    }
    
    cout << "The longest chain is ";
    
    std::set<int>::iterator it;
    for (it = unique_items.begin(); it != unique_items.end(); ++it) {
        cout << *it << " ";
    }
    
}