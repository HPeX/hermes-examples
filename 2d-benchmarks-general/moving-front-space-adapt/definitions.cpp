#include "definitions.h"

double CustomExactSolution::value(double x, double y) const 
{
  double S = s;
  double C = c;
  double t = *t_ptr;
  return ((x - x0)*(x - x1)*(y - y0)*(y - y1)*Hermes::atan(t)*(M_PI/2. - Hermes::atan(S*(-t + Hermes::sqrt(x*x + y*y)))))/C;
}

void CustomExactSolution::derivatives(double x, double y, double& dx, double& dy) const 
{
  double S = s;
  double C = c;
  double t = *t_ptr;
  dx = ((y - y0)*(y - y1)*Hermes::atan(t)*(M_PI*(2*x - x0 - x1) + (2*S*x*(x - x0)*(x - x1))/
				   (Hermes::sqrt(x*x + y*y)*(-1 + 2*S*S*t*Hermes::sqrt(x*x + y*y) - S*S*(t*t + x*x + y*y))) + 
         (4*x - 2*(x0 + x1))*Hermes::atan(S*(t - Hermes::sqrt(x*x + y*y)))))/(2.*C);
  dy = ((x - x0)*(x - x1)*Hermes::atan(t)*((2*S*y*(y - y0)*(y - y1))/(Hermes::sqrt(x*x + y*y)*(-1 + 2*S*S*t*Hermes::sqrt(x*x + y*y) - S*S*(t*t + x*x + y*y))) + 
         M_PI*(2*y - y0 - y1) + (4*y - 2*(y0 + y1))*Hermes::atan(S*(t - Hermes::sqrt(x*x + y*y)))))/(2.*C);
}

Ord CustomExactSolution::ord(Ord x, Ord y) const 
{
  return Ord(20);
}

double CustomFunction::value(double x, double y, double t) const 
{
  double S = s;
  double C = c;

  // Generated by Mathematica.
  double f = (2*S*x*(((x - x0)*(y - y0))/C + ((x - x1)*(y - y0))/C)*(y - y1)*Hermes::atan(t))/(Hermes::sqrt(x*x + y*y)*(1 
         + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))) + 
         (S*(x - x0)*(x - x1)*(y - y0)*(y - y1)*Hermes::atan(t))/(C*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))) - 
         ((x - x0)*(x - x1)*((2*Hermes::pow(S,3)*x*x*(-t + Hermes::sqrt(x*x + y*y)))/((x*x + y*y)*Hermes::pow(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2),2)) + 
         (S*x*x)/(Hermes::pow(x*x + y*y,1.5)*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))) - 
         S/(Hermes::sqrt(x*x + y*y)*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))))*(y - y0)*(y - y1)*Hermes::atan(t))/C - 
         ((x - x0)*(x - x1)*(y - y0)*((-2*S*y*Hermes::atan(t))/(Hermes::sqrt(x*x + y*y)*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))) + 
         ((2*Hermes::pow(S,3)*y*y*(-t + Hermes::sqrt(x*x + y*y)))/((x*x + y*y)*Hermes::pow(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2),2)) + 
         (S*y*y)/(Hermes::pow(x*x + y*y,1.5)*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))) - 
         S/(Hermes::sqrt(x*x + y*y)*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2))))*(y - y1)*Hermes::atan(t)))/C - 
         (2*(x - x0)*(x - x1)*(-((S*y*(y - y1)*Hermes::atan(t))/(Hermes::sqrt(x*x + y*y)*(1 + S*S*Hermes::pow(-t + Hermes::sqrt(x*x + y*y),2)))) + 
         Hermes::atan(t)*(M_PI/2. - Hermes::atan(S*(-t + Hermes::sqrt(x*x + y*y))))))/C + 
         ((x - x0)*(x - x1)*(y - y0)*(y - y1)*(M_PI/2. - Hermes::atan(S*(-t + Hermes::sqrt(x*x + y*y)))))/(C*(1 + t*t)) - 
         (2*(y - y0)*(y - y1)*Hermes::atan(t)*(M_PI/2. - Hermes::atan(S*(-t + Hermes::sqrt(x*x + y*y)))))/C;

  return f;
}

Ord CustomFunction::value(Ord x, Ord y) const 
{
  return Ord(20);
}

CustomVectorFormVol::CustomVectorFormVol(int i, std::string area,
					 Hermes::Hermes2DFunction<double>* coeff,
  GeomType gt)
  : VectorFormVol<double>(i), coeff(coeff), gt(gt)
{
  this->set_area(area);
  // If coeff is HERMES_ONE, initialize it to be constant 1.0.
  if (coeff == HERMES_ONE) this->coeff = new Hermes::Hermes2DFunction<double>(1.0);
}

CustomVectorFormVol::CustomVectorFormVol(int i, Hermes::vector<std::string> areas,
					 Hermes::Hermes2DFunction<double>* coeff,
  GeomType gt)
  : VectorFormVol<double>(i), coeff(coeff), gt(gt)
{
  this->set_areas(areas);
  // If coeff is HERMES_ONE, initialize it to be constant 1.0.
  if (coeff == HERMES_ONE) this->coeff = new Hermes::Hermes2DFunction<double>(1.0);
}

CustomVectorFormVol::~CustomVectorFormVol() 
{
  // FIXME: Should be deleted here only if it was created here.
  //if (coeff != HERMES_ONE) delete coeff;
};

double CustomVectorFormVol::value(int n, double *wt, Func<double> *u_ext[], Func<double> *v,
                                  Geom<double> *e, Func<double>* *ext) const 
{
  double result = 0;
  if (gt == HERMES_PLANAR) {
    for (int i = 0; i < n; i++) {
      result += wt[i] * static_cast<CustomFunction*>(coeff)->value(e->x[i], e->y[i], this->get_current_stage_time()) * v->val[i];
    }
  }
  else {
    if (gt == HERMES_AXISYM_X) {
      for (int i = 0; i < n; i++) {
        result += wt[i] * e->y[i] * static_cast<CustomFunction*>(coeff)->value(e->x[i], e->y[i], this->get_current_stage_time()) * v->val[i];
      }
    }
    else {
      for (int i = 0; i < n; i++) {
        result += wt[i] * e->x[i] * static_cast<CustomFunction*>(coeff)->value(e->x[i], e->y[i], this->get_current_stage_time()) * v->val[i];
      }
    }
  }
  return result;
}

Ord CustomVectorFormVol::ord(int n, double *wt, Func<Ord> *u_ext[], Func<Ord> *v,
  Geom<Ord> *e, Func<Ord>* *ext) const 
{
  Ord result = Ord(0);
  if (gt == HERMES_PLANAR) {
    for (int i = 0; i < n; i++) {
      result += wt[i] * coeff->value(e->x[i], e->y[i]) * v->val[i];
    }
  }
  else {
    if (gt == HERMES_AXISYM_X) {
      for (int i = 0; i < n; i++) {
        result += wt[i] * e->y[i] * coeff->value(e->x[i], e->y[i]) * v->val[i];
      }
    }
    else {
      for (int i = 0; i < n; i++) {
        result += wt[i] * e->x[i] * coeff->value(e->x[i], e->y[i]) * v->val[i];
      }
    }
  }

  return result;
}

VectorFormVol<double>* CustomVectorFormVol::clone() const 
{
  return new CustomVectorFormVol(*this);
}

CustomWeakFormPoisson::CustomWeakFormPoisson(std::string area,
  Hermes1DFunction<double>* coeff, Hermes2DFunction<double>* f,
  GeomType gt) : WeakFormsH1::DefaultWeakFormPoisson<double>()
{
  // Jacobian.
  // NOTE: The flag HERMES_NONSYM is important here.
  add_matrix_form(new WeakFormsH1::DefaultJacobianDiffusion<double>(0, 0, area, coeff, HERMES_NONSYM, gt));

  // Residual.
  add_vector_form(new WeakFormsH1::DefaultResidualDiffusion<double>(0, area, coeff, gt));
  add_vector_form(new CustomVectorFormVol(0, area, f, gt));
};

