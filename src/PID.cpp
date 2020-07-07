#include "PID.h"

PID::PID() : p_error(0.0), i_error(0.0), d_error(0.0),
    prev_cte(0.0), Kp(0.0), Ki(0.0), Kd(0.0)
{}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    d_error = cte - prev_cte;
    i_error = cte + i_error;
    prev_cte = cte;
}

double PID::TotalError() {
  return (Kp * p_error) + (Kd * d_error) + (Ki * i_error);
}
