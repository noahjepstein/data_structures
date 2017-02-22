//main tester

#include "sequenceA.h"

int main()
{
	SequenceA seq1('a');
	SequenceA seq2;
	SequenceA seq3('c');
	SequenceA seq4;

	SequenceA* seq1_ptr = &seq1;
	SequenceA* seq2_ptr = &seq2;
	SequenceA* seq3_ptr = &seq3;
	SequenceA*  seq4_ptr = &seq4;

	
	seq2.concatenate(seq1_ptr);
	seq2.concatenate(seq1_ptr);
	seq2.concatenate(seq2_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq4_ptr);
	seq2.concatenate(seq2_ptr);
	seq2.concatenate(seq4_ptr);
	seq4.concatenate(seq2_ptr);
	seq2.concatenate(seq1_ptr);
	seq2.concatenate(seq1_ptr);
	seq2.concatenate(seq2_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq3_ptr);
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq4_ptr);
	seq2.concatenate(seq2_ptr);
	seq2.concatenate(seq4_ptr);
	seq4.concatenate(seq2_ptr);
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq2_ptr->rest());
	seq2.concatenate(seq3_ptr);
	seq4.concatenate(seq2_ptr);
	
	
	
	


		
		

	seq2.print();
	cout << "I'm done!" << endl;


	return 0;
}
