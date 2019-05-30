
#include<vector>
#include<algorithm>
#include<stdexcept>

using std::vector;
using std::domain_error;
using std::sort;

double compute_median(vector<double> vec){
    // check that student enter some homework grade(s)
   typedef vector<double>::size_type vec_size;
    vec_size size = vec.size();
   if(size == 0)
    throw domain_error("Median of the vector is empty");



    // sort the homework grades
  sort(vec.begin(), vec.end());

  // compute median of homework grades
  vec_size mid = size/2;

  return size%2==0 ? vec[mid]+vec[mid-1]/2:vec[mid];


}
