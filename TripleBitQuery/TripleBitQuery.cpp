//---------------------------------------------------------------------------
// TripleBit
// (c) 2011 Massive Data Management Group @ SCTS & CGCL. 
//     Web site: http://grid.hust.edu.cn/triplebit
//
// This work is licensed under the Creative Commons
// Attribution-Noncommercial-Share Alike 3.0 Unported License. To view a copy
// of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/
// or send a letter to Creative Commons, 171 Second Street, Suite 300,
// San Francisco, California, 94105, USA.
//---------------------------------------------------------------------------

#include "TripleBit.h"
#include "TripleBitRepository.h"
#include "OSFile.h"
#include "MMapBuffer.h"

char *DATABASE_PATH;
char *QUERY_PATH;

int main(int argc, char *argv[]) {
	if (argc < 2 or std::string(argv[1]) == std::string("--help")) {
		fprintf(stderr, "Usage: %s <Database Directory>\n", argv[0]);
		return -1;
	}

	DATABASE_PATH = argv[1];

	TripleBitRepository *repo = TripleBitRepository::create(DATABASE_PATH);
	if (repo == NULL) {
		fprintf(stderr, "Usage: %s <Database Directory>\n", argv[0]);
		return -1;
	}

	repo->cmd_line();
	delete repo;

	return 0;
}
