
public class Veiculo {
    private String placa;
    private String tipo;
    private int numOcorrencias;
    private int anoFabricacao;

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

    public int getNumOcorrencias() {
        return numOcorrencias;
    }

    public void setNumOcorrencias(int numOcorrencias) {
        this.numOcorrencias = numOcorrencias;
    }

    public int getAnoFabricacao() {
        return anoFabricacao;
    }

    public void setAnoFabricacao(int anoFabricacao) {
        this.anoFabricacao = anoFabricacao;
    }

    public int calculaGarantia() {
        if (tipo.equals("PICKUP")) {
            return anoFabricacao + 5;
        } else if (tipo.equals("SUV")) {
            return anoFabricacao + 3;
        } else if (tipo.equals("POPULAR")) {
            return anoFabricacao + 2;
        } else {
            return 0;
        }
    }
}