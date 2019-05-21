#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Amp(double L, double omeg, double C, double R, double E0){
    return omeg * E0 / sqrt(pow((L * pow(omeg, 2.0)) - (1 / C), 2.0) + (pow(R, 2.0) * pow(omeg, 2.0)));
}

double phangleRad(double L, double omeg, double R, double C){
    return atan((L * omeg / R) - (1 / (R * C * omeg)));
}

double phangleDeg(double L, double omeg, double R, double C){
    return phangleRad(L, omeg, R, C) * 180 / M_PI;
}

double AV(double E0, double inSin){
    return E0 * sin(inSin);
}

double Vr(double R, double A, double inSin){
    return R * A * sin(inSin);
}

double Vl(double L, double omeg, double A, double inCos){
    return L * omeg * A * cos(inCos);
}

double Vc(double A, double C, double omeg, double inCos){
    return ((-1 * A) / (C * omeg)) * cos(inCos);
}

double It(double A, double inSin){
    return A * sin(inSin);
}

int main()
{
    double E0, f, R, L, C;
    int nstep; // #timesteps/cycle

    double T, omeg, dt, A, phi, phideg;
    double av, vt, vr, vl, vc, it, omt, omtphi, vdiff;

    int i = 0;

    cout << "Enter the Applied Voltage Amplitude (E0, volts): "; cin >> E0;
    cout << "Enter the Line Frequency            (f, hertz) : "; cin >> f;
    cout << "Enter the Resistor Value            (R, ohms)  : "; cin >> R;
    cout << "Enter the Inductor Value            (L, henrys): "; cin >> L;
    cout << "Enter the Capacitor Value           (C, farads): "; cin >> C;
    cout << "Enter the Points per AC period      (nStep)    : "; cin >> nstep;

    T = 1 / f;
    omeg = 2 * M_PI * f;
    dt = T / static_cast<double>(nstep);
    A = Amp(L, omeg, C, R, E0);
    phideg = phangleDeg(L, omeg, R, C);
    phi = phangleRad(L, omeg, R, C);

    cout << "RLC Circuit Summary:" << endl;
    cout << "\n\tVoltage:         " << E0 << "-Volts @ " << f << "-Hz" << endl;
    cout <<   "\tResistor Value:  " << R << "-ohms" << endl;
    cout <<   "\tInductor Value:  " << L << "-H" << endl;
    cout <<   "\tCapacitor Value: " << scientific << C << fixed << "-F" << endl;

    cout << fixed << setprecision(3);

    cout << "\n\tCalculated Parameters:" << endl;
    cout << "\t    Current Amplitude: " << setw(8) << A << "-amps" << endl;
    cout << "\t    Phase Angle:       " << setw(8) << phideg << "-degrees\n" << endl;
    cout << "\tIter.Time\tAV\t I\tVR\tVL\tVC\tVT   Vdiff" << endl;

    for(double t = 0; t < 2*T; t = t + dt){
        omt = omeg*t;
        omtphi = omt - phi;
        av = AV(E0, omt);
        vr = Vr(R, A, omtphi);
        vl = Vl(L, omeg, A, omtphi);
        vc = Vc(A, C, omeg, omtphi);
        vt = vr + vl + vc;
        it = It(A, omtphi);
        vdiff = av - vt;
        cout << "\t" << setw(2) << i;
        cout << setw(8) << t;
        cout << setw(8) << av;
        cout << setw(8) << it;
        cout << setw(8) << vr;
        cout << setw(8) << vl;
        cout << setw(8) << vc;
        cout << setw(8) << vt;
        cout << setw(8) << vdiff;
        cout << endl;
        i++;
    }

    return 0;
}
