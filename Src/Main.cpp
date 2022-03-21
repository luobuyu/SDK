#include "Config.h"
#include "Instance.h"
#include "Solve.h"

void run_single_instance(const string& ins_str) {
	Environment env(ins_str);
	Solve solve(env, cfg);
	solve.run();
	solve.record_sol(env.solution_path());
}

void run_all_instances() {
	for (auto& ins : ins_list) {
		cout << "load instance " << ins << endl;
		run_single_instance(ins);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2)
	{
		cerr << "Error parameter. See 'placement.exe timeout random_seed'." << endl;
	}
	else if (argc == 1)
	{
		// ���治���κβ�����ʱ��ȫ������
		cout << "Run all instances..." << endl;
		run_all_instances();
	}
	else if (argc == 2)
	{
		// �����������·����ʱ��ֻ����һ������
		run_single_instance(argv[1]);
	}
	return 0;
}
