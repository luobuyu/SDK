#ifndef _SRC_SOLVE_H_
#define _SRC_SOLVE_H_

#include "Instance.h"
#include "Utils.h"

using namespace Debug;

class Solve {

private:
	const Environment& _env;
	const Config& _cfg;

	Instance _ins;
	default_random_engine _gen;
	Timer timer;

	double _duration; // ���Ž����ʱ��
	int _iteration;   // ���Ž���ֵ�������


public:

	Solve() = delete;

	Solve(const Environment& env, const Config& cfg) :
		_env(env), _cfg(cfg), _ins(env),
		_gen(_cfg.random_seed), timer(cfg.timeout),
		_duration(0), _iteration(0)
		// �� _obj_area��ʼ��Ϊ���ֵ
	{
		// ��ʼ������
		
	}

	~Solve()
	{

	}

	void init_solution()
	{
		
	}

	void run()
	{

	}

	// �����д���ļ�
	void record_sol(const string& sol_path) const
	{
		if (freopen(sol_path.c_str(), "w", stdout) == NULL) 
		{
			cerr << "Error solution path: can not open " << sol_path << endl;
			return;
		}
		record_sol();
	}

	void record_sol() const
	{

	}

	// ���ӻ����
	void show_sol(SetInt& sol) const
	{
		for (auto& x : sol)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	// д����־�ļ�����������Ϊд���׼������
	void record_log(const string& log_path)
	{
		if (freopen(log_path.c_str(), "a", stderr) == NULL)
		{
			cerr << "Error log path: can not open " << log_path << endl;
			return;
		}
		ofstream log_file(log_path, ios::app);
		log_file.seekp(0, ios::end);
		if (log_file.tellp() <= 0) { record_log_header(); }
		record_log_data();
	}

	// д���׼������
	void record_log()
	{
		record_log_header();
		record_log_data();
	}

	/// ������Ƿ���ȷ
	bool check()
	{
		return true;
	}
private:
	void record_log_header()
	{
		writeStream("date", "instance", "randomSeed",
			"obj_iterTimes", "obj_time", "all_time");
	}

	void record_log_data()
	{
		writeStream(Date::to_format_str(), _env.instance_name(), _cfg.random_seed,
			_iteration, _duration, timer.getDuration());
	}

	int rand(int lb, int ub) { return _gen() % (ub - lb) + lb; } // [lb, ub-1]

	int rand(int ub) { return _gen() % ub + 1; } // [1, ub]

	double rand() { return uniform_real_distribution<double>(0, 1)(_gen); }

};
#endif // !_SRC_SOLVE_H_

