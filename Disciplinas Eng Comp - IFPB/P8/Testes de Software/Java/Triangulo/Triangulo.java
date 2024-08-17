public class Triangulo {
    private double ladoA;
    private double ladoB;
    private double ladoC;

    public Triangulo(double ladoA, double ladoB, double ladoC) {
        this.ladoA = ladoA;
        this.ladoB = ladoB;
        this.ladoC = ladoC;
    }

    public String classificar() {
        if (!ehTrianguloValido()) {
            return "Não é um triângulo válido";
        }

        if (ladoA == ladoB && ladoB == ladoC) {
            return "Equilátero";
        } else if (ladoA == ladoB || ladoB == ladoC || ladoA == ladoC) {
            return "Isósceles";
        } else {
            return "Escaleno";
        }
    }

    private boolean ehTrianguloValido() {
        return (ladoA + ladoB > ladoC) && (ladoB + ladoC > ladoA) && (ladoA + ladoC > ladoB);
    }

    public boolean ehEquilatero() {
        return ladoA == ladoB && ladoB == ladoC;
    }

    public boolean ehIsosceles() {
        return ladoA == ladoB || ladoB == ladoC || ladoA == ladoC;
    }

    public boolean ehEscaleno() {
        return ladoA != ladoB && ladoB != ladoC && ladoA != ladoC;
    }

    public double calculaPerimetro() {
        return ladoA + ladoB + ladoC;
    }
}