
public class Main {
    public static void main(String[] args) {
        // Criando uma instância da classe Livro
        Livro livro1 = new Livro("Java Programming", 2023, "Autor Desconhecido", "123-456-789");
        Livro livro2 = new Livro("Aprendendo Python", 2020, "Guido van Rossum", "987-654-321");

        // Exibindo informações do livro1
        System.out.println("Livro 1:");
        System.out.println("Nome: " + livro1.getNome());
        System.out.println("Edição: " + livro1.getEdicao());
        System.out.println("Autor: " + livro1.getAutor());
        System.out.println("ISBN: " + livro1.getIsbn());
        System.out.println("É lançamento? " + (livro1.verificaLancamento() ? "Sim" : "Não"));

        System.out.println();

        // Exibindo informações do livro2
        System.out.println("Livro 2:");
        System.out.println("Nome: " + livro2.getNome());
        System.out.println("Edição: " + livro2.getEdicao());
        System.out.println("Autor: " + livro2.getAutor());
        System.out.println("ISBN: " + livro2.getIsbn());
        System.out.println("É lançamento? " + (livro2.verificaLancamento() ? "Sim" : "Não"));
    }
}
