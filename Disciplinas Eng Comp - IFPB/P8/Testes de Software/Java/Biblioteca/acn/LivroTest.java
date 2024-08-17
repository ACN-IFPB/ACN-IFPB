
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class LivroTest {

    @Test
    public void testVerificaLancamento_true() {
        // Criando um livro com edição maior que 2022
        Livro livro = new Livro("Livro Recente", 2023, "Autor Famoso", "111-222-333");

        // Verificando se o método verificaLancamento retorna true
        assertTrue(livro.verificaLancamento());
    }

    @Test
    public void testVerificaLancamento_false() {
        // Criando um livro com edição menor ou igual a 2022
        Livro livro = new Livro("Livro Antigo", 2020, "Autor Famoso", "444-555-666");

        // Verificando se o método verificaLancamento retorna false
        assertFalse(livro.verificaLancamento());
    }

    @Test
    public void testGettersAndSetters() {
        // Criando uma instância da classe Livro
        Livro livro = new Livro("Livro Teste", 2021, "Autor Teste", "777-888-999");

        // Testando os métodos setters e getters
        livro.setNome("Novo Nome");
        livro.setEdicao(2022);
        livro.setAutor("Novo Autor");
        livro.setIsbn("000-111-222");

        assertEquals("Novo Nome", livro.getNome());
        assertEquals(2022, livro.getEdicao());
        assertEquals("Novo Autor", livro.getAutor());
        assertEquals("000-111-222", livro.getIsbn());
    }
}
