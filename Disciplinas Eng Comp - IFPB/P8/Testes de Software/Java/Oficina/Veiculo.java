package oficina;

public class Veiculo {
    private String placa;
    private String tipo;
    private int anoFabricacao;
    private int numOcorrencias;

    public Veiculo(String placa, String tipo, int anoFabricacao) {
        this.placa = placa;
        this.tipo = tipo;
        this.anoFabricacao = anoFabricacao;
        this.numOcorrencias = 0;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public int getAnoFabricacao() {
        return anoFabricacao;
    }

    public void setAnoFabricacao(int anoFabricacao) {
        this.anoFabricacao = anoFabricacao;
    }

    public int getNumOcorrencias() {
        return numOcorrencias;
    }

    public void incrementaOcorrencias() {
        this.numOcorrencias++;
    }

    public int calculaGarantia() {
        switch (tipo.toUpperCase()) {
            case "PICKUP":
                return anoFabricacao + 5;
            case "SUV":
                return anoFabricacao + 3;
            case "POPULAR":
                return anoFabricacao + 2;
            default:
                return anoFabricacao; // Sem garantia adicional
        }
    }
}
