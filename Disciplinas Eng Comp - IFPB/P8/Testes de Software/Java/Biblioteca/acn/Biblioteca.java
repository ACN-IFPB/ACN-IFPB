import java.util.ArrayList;

public class Biblioteca {
    private String nome;
    private String cnpj;
    private int anoFundacao;
    private ArrayList<Livro> listaLivros;

    // Construtor
    public Biblioteca(String nome, String cnpj, int anoFundacao) {
        this.nome = nome;
        this.cnpj = cnpj;
        this.anoFundacao = anoFundacao;
        this.listaLivros = new ArrayList<>();
    }

    // Métodos getters e setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    public int getAnoFundacao() {
        return anoFundacao;
    }

    public void setAnoFundacao(int anoFundacao) {
        this.anoFundacao = anoFundacao;
    }

    public ArrayList<Livro> getListaLivros() {
        return listaLivros;
    }

    // Método para adicionar um livro
    public void adicionarLivro(Livro livro) {
        this.listaLivros.add(livro);
    }

    // Método para remover um livro
    public void removerLivro(Livro livro) {
        this.listaLivros.remove(livro);
    }

    // Método para consultar todos os livros
    public ArrayList<Livro> consultarLivros() {
        return new ArrayList<>(this.listaLivros);
    }

    // Método patrimonioHistorico
    public boolean patrimonioHistorico() {
        return this.anoFundacao < 1980;
    }

    // Método acervoPremium
    public boolean acervoPremium() {
        int contadorLancamentos = 0;
        for (Livro livro : listaLivros) {
            if (livro.verificaLancamento()) {
                contadorLancamentos++;
            }
            if (contadorLancamentos >= 5) {
                return true;
            }
        }
        return false;
    }
}

