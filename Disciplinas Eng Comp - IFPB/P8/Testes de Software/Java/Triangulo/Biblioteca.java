import java.util.List;

/*

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

    // Metodo para adicionar um livro
    public void adicionarLivro(Livro livro) {
        this.listaLivros.add(livro);
    }

    // Metodo para remover um livro
    public void removerLivro(Livro livro) {
        this.listaLivros.remove(livro);
    }

    // Metodo para consultar todos os livros
    public ArrayList<Livro> consultarLivros() {
        return new ArrayList<>(this.listaLivros);
    }

    // Metodo patrimonioHistorico
    public boolean patrimonioHistorico() {
        return this.anoFundacao < 1980;
    }

    // Metodo acervoPremium
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


*/
public class Biblioteca {
    private String nome;
    private int fundacao;
    private List livros;

    public Biblioteca(String nome, int fundacao) {
        this.nome = nome;
        this.fundacao = fundacao;
        this.livros = new ArrayList<>();
    }

    public void adicionarLivro(Livro livro) {
        livros.add(livro);
    }

    public boolean patrimonioHistorico() {
        return fundacao < 1950;
    }

    public int quantidadeLivros() {
        return livros.size();
    }
}