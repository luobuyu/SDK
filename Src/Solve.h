#ifndef _SRC_SOLVE_H_
#define _SRC_SOLVE_H_

#include "Instance.h"
#include "Utils.h"

using namespace utils;
using namespace fast_io;
class Solve {

private:
	const Environment& _env;
	const Config& _cfg;

	const Instance _ins;
	default_random_engine _gen;
	Timer timer;

	double _duration; // ���Ž����ʱ��
	int _iteration;   // ���Ž���ֵ�������


public:

	Solve() = delete;

	Solve(const Environment& env, const Config& cfg) :
		_env(env), _cfg(cfg), _ins(env), _gen(_cfg.random_seed), timer(cfg.timeout)
		 {}	// �� _obj_area��ʼ��Ϊ���ֵ

	void run() {
		while (!timer.isTimeout()) {
			
		}
	}

	// �����д���ļ�
	void record_sol(const string& sol_path) const {

	}
	// ���ӻ����
	void draw_sol(const string& html_path) const {

	}
	// д����־�ļ�
	void record_log() {
		// д���ͷ
		writeLog(_env.log_path(), LineType::HEAD, "instance", "randomSeed", "iterTimes", "time");
		// д��������
		writeLog(_env.log_path(), LineType::LINE, _env.instance_name(), _cfg.random_seed, _iteration, timer.getDuration());
	}

private:

	/// ������Ƿ���ȷ
	void check() {

	}


};
#endif // !_SRC_SOLVE_H_

