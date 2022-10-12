// unique
sort(a.begin(), a.end());
a.resize(unique(a.begin(), a.end()) - a.begin());
// O(n) a[k] = kth small, a[i] < a[k] if i < k
nth_element(a.begin(), a.begin()+k, a.end());
// stable_sort(a.begin(), a.end())
// lower_bound: first element >= val
// upper_bound: first element >  val
// set_union, set_intersection, set_difference,
//   set_symmetric_difference
set_union(a.begin(), a.end(), b.begin(), b.end(),
  inserter(c, c.begin()));
//next_permutation prev_permutation(sort/reverse first)
do{ for(auto i : a) cout << i << ' ';
} while(next_permutation(a.begin(), a.end()));
