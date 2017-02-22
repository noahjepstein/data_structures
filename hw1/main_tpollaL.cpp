//main tester

#include "sequenceL.h"

int main()
{
	SequenceL seq1('a');
	SequenceL seq2;
	SequenceL seq3('c');
	SequenceL seq4;

	SequenceL* seq1_ptr = &seq1;
	SequenceL* seq2_ptr = &seq2;
	SequenceL* seq3_ptr = &seq3;
	SequenceL* seq4_ptr = &seq4;

	
	seq2.concatenate(seq1_ptr);
    seq2.print();
	seq2.concatenate(seq1_ptr);
    seq2.print();
	/*seq2.concatenate(seq2_ptr);
    seq2.print();
	seq2.concatenate(seq3_ptr);
    seq2.print();
	seq2.concatenate(seq3_ptr);
    seq2.print();
	seq2.concatenate(seq3_ptr);
    seq2.print();
	seq2.concatenate(seq3_ptr);
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq4_ptr);
	seq2.print();
    seq2.concatenate(seq2_ptr);
	seq2.print();
    seq2.concatenate(seq4_ptr);
	seq2.print();
    seq4.concatenate(seq2_ptr);
	seq2.print();
    seq2.concatenate(seq1_ptr);
	seq2.print();
    seq2.concatenate(seq1_ptr);
	seq2.print();
    seq2.concatenate(seq2_ptr);
	seq2.print();
    seq2.concatenate(seq3_ptr);
	seq2.print();
    seq2.concatenate(seq3_ptr);
	seq2.print();
    seq2.concatenate(seq3_ptr);
	seq2.print();
    seq2.concatenate(seq3_ptr);
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq4_ptr);
	seq2.print();
    seq2.concatenate(seq2_ptr);
	seq2.print();
    seq2.concatenate(seq4_ptr);
	seq2.print();
    seq4.concatenate(seq2_ptr);
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq2_ptr->rest());
	seq2.print();
    seq2.concatenate(seq3_ptr);
	seq2.print();
    seq4.concatenate(seq2_ptr);
    seq2.print();*/
	
	


		
		

	seq2.print();
	cout << "I'm done!" << endl;


	return 0;
}
