#include "random_vector.h"
// TODO: add any include you might require

RandomVector::RandomVector(int size, double max_val) { 
  // TODO: Write your code here

  double r;
  for (int i = 0; i<size; i++){
    r = static_cast<double>(std::rand()) / RAND_MAX;
    vect.push_back(r * max_val);
  }
  
}

void RandomVector::print(){
  // TODO: Write your code here

  for (const auto &val : vect){
    std::cout<<val<<" ";
  }
  std::cout<<std::endl;
}

double RandomVector::mean(){
  // TODO: Write your code here

  double sum=0.0;
  for (const auto &val : vect){
    sum += val;
  }
  return sum / vect.size();
}

double RandomVector::max(){
  // TODO: Write your code here

  // simple Linear Search:
  double maxval = vect[0];
  for (const auto &val : vect){
    if (maxval<val){
      maxval = val;
    }
  }
  return maxval;
}

double RandomVector::min(){
  //TODO:  Write your code here
  
  //Again a linear search: 
  double minval = vect[0];
  for (const auto &val : vect){
    if (minval>val){
      minval = val;
    }
  }
  return minval;
}

void RandomVector::printHistogram(int bins){
  // TODO: Write your code here
  
  double min = this->min();
  double max = this->max();

  double step = (max - min) / bins;

  double low;
  double high;

  for (int i = 1; i<=bins; i++){
    low = min + (i-1) * step;
    high = min + i * step; 
    for (const auto &val : vect ){
      if ( val >= low && (val < high || (i==bins && val==high) )){
        std::cout<<"***"<<"\t";
      }
    }
    std::cout<<std::endl;
  }
}
