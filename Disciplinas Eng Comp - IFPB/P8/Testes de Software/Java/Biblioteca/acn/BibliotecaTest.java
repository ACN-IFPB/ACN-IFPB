import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.ArrayList;

public class BibliotecaTest {

    @Test
    public void testPatrimonioHistorico_true() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Antiga", "00.000.000/0001-00", 1975);
        assertTrue(biblioteca.patrimonioHistorico());
    }

    @Test
    public void testPatrimonioHistorico_false() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Moderna", "11.111.111/1111-11", 1990);
        assertFalse(biblioteca.patrimonioHistorico());
    }

    @Test
    public void testGettersAndSetters() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Teste", "22.222.222/2222-22", 2000);
        biblioteca.setNome("Nova Biblioteca");
        biblioteca.setCnpj("33.333.333/3333-33");
        biblioteca.setAnoFundacao(1985);

        assertEquals("Nova Biblioteca", biblioteca.getNome());
        assertEquals("33.333.333/3333-33", biblioteca.getCnpj());
        assertEquals(1985, biblioteca.getAnoFundacao());
    }

    @Test
    public void testAcervoPremium_true() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Premium", "44.444.444/4444-44", 1950);

        // Adicionando 5 livros que são lançamentos (edição > 2022)
        biblioteca.adicionarLivro(new Livro("Livro 1", 2023, "Autor A", "123-123-123"));
        biblioteca.adicionarLivro(new Livro("Livro 2", 2023, "Autor B", "124-124-124"));
        biblioteca.adicionarLivro(new Livro("Livro 3", 2024, "Autor C", "125-125-125"));
        biblioteca.adicionarLivro(new Livro("Livro 4", 2024, "Autor D", "126-126-126"));
        biblioteca.adicionarLivro(new Livro("Livro 5", 2025, "Autor E", "127-127-127"));

        // Verificando se acervoPremium retorna true
        assertTrue(biblioteca.acervoPremium());
    }

    @Test
    public void testAcervoPremium_false() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Regular", "55.555.555/5555-55", 2000);

        // Adicionando 4 livros que são lançamentos (edição > 2022)
        biblioteca.adicionarLivro(new Livro("Livro 1", 2023, "Autor A", "123-123-123"));
        biblioteca.adicionarLivro(new Livro("Livro 2", 2023, "Autor B", "124-124-124"));
        biblioteca.adicionarLivro(new Livro("Livro 3", 2024, "Autor C", "125-125-125"));
        biblioteca.adicionarLivro(new Livro("Livro 4", 2024, "Autor D", "126-126-126"));

        // Verificando se acervoPremium retorna false
        assertFalse(biblioteca.acervoPremium());
    }
}
