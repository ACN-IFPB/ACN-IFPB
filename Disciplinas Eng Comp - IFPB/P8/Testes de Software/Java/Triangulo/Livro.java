public class Livro {
    private String nome;
    private int edicao;
    private String autor;
    private String isbn;
    private String titulo;
    private int anoPublicacao;

    public Livro(String nome, int edicao, String autor, String isbn, String titulo, int anoPublicacao) {
        this.nome = nome;
        this.edicao = edicao;
        this.autor = autor;
        this.isbn = isbn;
        this.titulo = titulo;
        this.anoPublicacao = anoPublicacao;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getEdicao() {
        return edicao;
    }

    public void setEdicao(int edicao) {
        this.edicao = edicao;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public boolean verificaLancamento() {
        int anoEdicao = 2022;
        return edicao > anoEdicao;
    }

    public Livro(String titulo, int anoPublicacao) {
        this.titulo = titulo;
        this.anoPublicacao = anoPublicacao;
    }

    public String getTitulo() {
        return titulo;
    }

    public int getAnoPublicacao() {
        return anoPublicacao;
    }
}