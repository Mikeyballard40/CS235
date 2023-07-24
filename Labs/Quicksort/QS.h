//**** YOU MAY NOT MODIFY THIS DOCUMENT ****/
#ifndef QS_H_
#define QS_H_

#include <sstream>
#include <iostream>
#include <string>
#include "QSInterface.h"

using namespace std;

#define DEFALAULT_C 1

template<typename T>
class QS : public QSInterface<T>
{
private:
    T *array;
    int cap;
    int num_items;//counts num of items and next index position;
	int comp;
	int ex;
    
public:
	QS() : 
    cap(DEFALAULT_C),
    num_items(0),
	comp(0),
	ex(0),
    array(new T[DEFALAULT_C]) {}

	virtual ~QS() {
        delete[] array;
		
    }

    void Quicksort(int num){

		delete[] array;
		num_items = 0;
		cap = num;
        
		array = new T[num];
    }

	/** Add an element to the QuickSort array. Dynamically grow array as needed. */
	virtual bool addElement(T element){
		if(num_items == (cap - 1)){

			cap = cap * 2;
			T *temp_array = new T[cap];
			for(int i = 0; i < cap/2; i++){
				temp_array[i] = array[i];
			}
			array = temp_array;
        	// delete[] temp_array;
		}
		array[num_items] = element;

		num_items++;

	    cout << toString() << endl;

    };

	/** Sort the elements of a QuickSort subarray using median and partition functions. */
	virtual bool sort(size_t left, size_t right){
		
		if (left < right) {
			size_t pivotIndex = medianOfThree(left, right);
			size_t newPivotIndex = partition(left, right, pivotIndex);
			
			if (newPivotIndex == -1) {
				return false;
			}


			sort(left, newPivotIndex);
			sort(newPivotIndex + 1, right);
		}
		return true;
    };

	/** Sort all elements of the QuickSort array using median and partition functions. */
	virtual bool sortAll(){
		
		size_t MOT, pivI;
		MOT = medianOfThree(0, num_items);

		if (MOT == -1) {
			return false;
		}

		pivI = partition(0, num_items, MOT);
		

		sort(0, pivI);
		sort(pivI + 1, num_items);

		return true;
    };

// 	Note that this function will be recursive. Most people use sortAll() as a recursive starter function that then call another function to do the sorting.
// To revised quicksort, first call your medianOfThree() function to sort the first, middle, and last elements and return the pivot index.
// Now, call your partition() function, using the index returned from medianOfThree() as the pivot index. This function will return a new pivot index where your array is split.
// Finally, recursively call your sort() function on the two halves of your array, with one half from the left to the pivot and the other half from the pivot to the right.
// Note: Reset exchange and comparison counters at the beginning of Sort and SortAll commands for the Bonus test.




	/** Removes all items from the QuickSort array. */
	virtual bool clear(){
		num_items = 0;
		return true;
    };

	/** Return size of the QuickSort array. */
	virtual size_t capacity() const {
        return cap;
    };

	/** Return number of elements in the QuickSort array. */
	virtual size_t size() const{
		return num_items;
    };

	/** The median of three pivot selection has two parts:
	1) Calculates the middle index by averaging the given left and right indices:
	   middle = (left + right)/2
	2) Then bubble-sorts the values at the left, middle, and right indices.

	After this method is called, data[left] <= data[middle] <= data[right].

	@param left - the left boundary for the subarray from which to find a pivot
	@param right - the right + 1 boundary for the subarray from which to find a pivot
	@return the index of the pivot (middle index).
	Return -1 if  1) the array is empty,
	              2) if either of the given integers is out of bounds,
	              3) or if the left index is not less than the right index.
	*/
	virtual int medianOfThree(size_t left, size_t right){

// 		The Median-of-Three function takes left and right indexes as parameters and then calculates the index in the middle of the indexes (rounding down if necessary).
// 		Sort the left, middle, and right numbers from smallest to largest in the array.
// 		Finally, return the index of the middle value. This will be your pivot value in the sortAll() function.
//		Note that medianOfThree() is not used in your partition() function. The pivot value will be supplied by an input file Partition command.

		size_t middle;
		size_t temp;

		if(size() == 0 || (left < 0 || right > num_items) || left >= right){ //right > num_items or right > cap???   or left >= right - 1     //check for final condition switch
			return -1;
		}

		middle = (right + left) / 2;

		if (array[middle] > array[right-1]){
			swap(array[middle], array[right-1]);
		} if(array[left] > array[middle]){
			swap(array[middle], array[left]);
		} if (array[middle] > array[right-1]){
			swap(array[middle], array[right-1]);
		}

		return middle;


    };

	/** Partitions a subarray around a pivot value selected according
	to median-of-three pivot selection. Because there are multiple ways
	to partition a list, follow the algorithm on page 611.

	The values less than or equal to the pivot should be placed to the left of the pivot;
	the values greater than the pivot should be placed to the right of the pivot.

	@param left - left index for the subarray to partition.
	@param right - right index + 1 for the subarray to partition.
	@param pivotIndex - index of the pivot in the subarray.
	@return the pivot's ending index after the partition completes:
	Return -1 if  1) the array is empty,
	              2) if any of the given indexes are out of bounds,
	              3) if the left index is not less than the right index.
	*/
	virtual int partition(size_t left, size_t right, size_t pivotIndex){
		// The partition() function should begin by swapping the leftmost element of the array with the pivot index element.

		if(size() == 0 || (left < 0 || right - 1 > num_items) || left >= right - 1 || left > pivotIndex > right - 1){ //right > num_items or right > cap???   or left >= right - 1     //check for final condition switch
			return -1;
		}

		//switch the left most element of the array with the pivot index element
		T temp;
		swap(array[pivotIndex], array[left]);

		T up = left + 1;
		T down = right - 1;

		do{
			while((array[up] <= array[left] && up < right - 1)){ //Incrememnt up until up selects the first element greater than the pivot value or up has reached last - 1  ---  (up > pivotIndex || up == right - 1)
				comp++;
				++up;
			}

			while(array[down] > array[left] && down != left){ //down until selects the first element less than or equal to the pivot value or down has reached first  ---  (down <= pivotIndex || down == left)
				comp++;
				--down;
			}

			if (up < down){
				ex++;
				swap(array[up], array[down]);
			}
		} while (up < down); //up << right or down?
		swap(array[left], array[down]);

	return down;


    };

	/** @return: comma delimited string representation of the array. */
	virtual string toString() const{
		stringstream ss;
		if(num_items == 0) ss << "Empty";
		else{
			for (int i = 0; i < num_items; i++){
				cout << "i: " << i << ",  array[i]: " << array[i] << endl;
				if(i+1 == num_items){
					ss << array[i];
				}else{
					ss << array[i] << ",";
				}
			}
		}
		return ss.str();
    };

	virtual string stat(){
		stringstream ss;
		ss << comp << "," << ex;
		return ss.str();
	}
	 //The Stats command outputs the number of comparisons and exchanges used by the sort commands.


};

#endif /* QSINTERFACE_H_ */