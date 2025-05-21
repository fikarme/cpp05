Collecting workspace information# CPP Module 05: Exception Handling

This module focuses on exception handling in C++ through a series of exercises that build upon each other to create a bureaucratic system. Here's an explanation of each exercise:

## Exercise 00: Bureaucrat Class

This exercise introduces you to exception handling by implementing a `Bureaucrat` class:

- **Attributes**:
  - A constant name
  - A grade between 1 (highest) and 150 (lowest)

- **Key functionality**:
  - Exception handling for invalid grades (`GradeTooHighException` and `GradeTooLowException`)
  - Increment/decrement methods for changing grade with proper exception handling
  - Getters for name and grade
  - Overloaded insertion operator to display bureaucrat information

This forms the foundation for the bureaucratic system, where grade 1 represents the highest authority and 150 the lowest.

## Exercise 01: Form Class

Building on Ex00, this exercise adds forms that bureaucrats can interact with:

- **Attributes**:
  - A constant name
  - A signed status (initially false)
  - A constant grade required for signing
  - A constant grade required for execution

- **Key functionality**:
  - `beSigned()` method that checks if a bureaucrat has high enough grade to sign
  - `signForm()` method added to `Bureaucrat` to attempt signing
  - Similar exception handling to the previous exercise

## Exercise 02: Concrete Form Types

This exercise expands on the form system:

- The base form class becomes an abstract class (`AForm`)
- Three concrete form types are added:
  1. **ShrubberyCreationForm**: Creates a file with ASCII trees (sign: 145, exec: 137)
  2. **RobotomyRequestForm**: Attempts robotomization with 50% success rate (sign: 72, exec: 45)
  3. **PresidentialPardonForm**: Grants a presidential pardon (sign: 25, exec: 5)

- **Key functionality**:
  - `execute()` method in base class and implementations in concrete classes
  - `executeForm()` added to `Bureaucrat` to attempt executing forms
  - Checks that form is signed and bureaucrat has sufficient grade

The implementation in the ShrubberyCreationForm.cpp shows how it creates ASCII art trees in a target file.

## Exercise 03: Intern Class

The final exercise introduces a factory pattern:

- **Intern class**: Creates forms based on form name and target
  - No name, grade, or unique characteristics
  - `makeForm()` function that returns appropriate form object based on name
  - Error handling for non-existent form types
  - Simplified form creation process

This completes the bureaucratic system with a way to automatically create the right type of form without direct instantiation.

Each exercise must follow proper C++ practices like Orthodox Canonical Form and adhere to the C++98 standard with appropriate error handling.





# Differences Between Form and AForm

You're right about the main change - Form became an abstract class and was renamed to AForm. Here are the key differences:

## 1. Abstract vs Concrete
- **Form**: Concrete class that can be instantiated
- **AForm**: Abstract class (note the pure virtual function with `= 0`)

## 2. Access Modifiers
- **Form**: Attributes are `private`
- **AForm**: Attributes are `protected` (allows derived classes to access them)

## 3. Virtual Functions
- **AForm** added `virtual` to methods to support polymorphism
- Added pure virtual method: `execute(Bureaucrat const &executor) const = 0`

## 4. Exception Handling
- **AForm** adds an additional exception class: `FormNotSigned`

## 5. Inheritance Support
- **AForm** is designed to be a base class for the concrete form types (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm)
- The `virtual` methods allow derived classes to override functionality
- `protected` attributes allow derived classes to access the base class data

This change follows the exercise requirements to make Form an abstract base class that concrete form types will inherit from. The 'A' prefix is a common naming convention to indicate "Abstract".




virtual func, runtime cost, polymorphism, keyword override, dynamic dispatch



# C++ Sanal Fonksiyonlar ve Polimorfizm Notları

## 1. Sanal Fonksiyonlar (Virtual Functions)

- **Tanım**: `virtual` anahtar kelimesi ile işaretlenen ve türetilmiş sınıflar tarafından ezilebilen (override edilebilen) fonksiyonlardır.
- **Sözdizimi**: `virtual dönüş_tipi fonksiyon_adı(parametreler);`
- **Saf Sanal Fonksiyonlar**: `= 0` ifadesiyle tanımlanan ve türetilmiş sınıfların uygulamak zorunda olduğu fonksiyonlardır.
  ```cpp
  virtual void execute(Bureaucrat const &executor) const = 0;
  ```
- **Amaç**: Türetilmiş sınıflara, temel sınıfın işlevselliğini değiştirme imkanı sağlar.
- **Sanal Yıkıcılar**: Polimorfik sınıflarda bellek sızıntılarını önlemek için yıkıcı fonksiyonlar genellikle sanal olarak tanımlanır.
  ```cpp
  virtual ~AForm(); // Doğru yıkma sıralaması için
  ```

## 2. Çalışma Zamanı Maliyeti (Runtime Cost)

- **vTable (Sanal Fonksiyon Tablosu)**: Her sanal fonksiyona sahip sınıf için derleyici bir vTable oluşturur.
- **vPtr (Sanal İşaretçi)**: Sanal fonksiyona sahip her nesne, sınıfın vTable'ına işaret eden bir vPtr içerir.
- **Bellek Maliyeti**: 
  - Her polimorfik nesne için ek bir işaretçi boyutu (genellikle 4 veya 8 byte)
  - Her polimorfik sınıf için bir vTable
- **Performans Maliyeti**:
  - İlave bir işaretçi dereferans işlemi
  - Çağrı sırasında fonksiyon adresinin vTable'dan bulunması
  - İşlemci önbellek isabetlerinde potansiyel düşüş
- **Not**: Modern işlemcilerde bu maliyet genellikle göz ardı edilebilir düzeydedir.

## 3. Polimorfizm (Polymorphism)

- **Tanım**: Farklı türlerin, aynı arayüz üzerinden farklı davranışlar sergileyebilme yeteneğidir.
- **Türleri**:
  - **Statik (Derleme Zamanı)**: Fonksiyon veya operatör aşırı yükleme
  - **Dinamik (Çalışma Zamanı)**: Sanal fonksiyonlar aracılığıyla
- **Avantajları**:
  - Kod yeniden kullanılabilirliği
  - Genişletilebilirlik
  - Soyutlama
- **Örnek**:
  ```cpp
  AForm* form = new ShrubberyCreationForm("Garden");
  form->execute(bureaucrat); // ShrubberyCreationForm'un execute metodu çağrılır
  ```

## 4. Override Anahtar Kelimesi

- **Tanım**: C++11 ile eklenen, bir metodun üst sınıftaki sanal metodu ezdiğini açıkça belirten anahtar kelime.
- **Amaç**: Derleme zamanında hata yakalama sağlar:
  - İmza uyuşmazlıklarını yakalar
  - Ezilemeyecek metotları ezme girişimlerini engeller
- **Kullanım**:
  ```cpp
  class ShrubberyCreationForm : public AForm {
  public:
      void execute(Bureaucrat const &executor) const override;
  };
  ```
- **Faydaları**:
  - Kodun kendini belgelendirmesi
  - Yeniden düzenleme sırasında güvenlik
  - İmza değişikliklerinde otomatik uyum kontrolü

## 5. Dinamik Dağıtım (Dynamic Dispatch)

- **Tanım**: Çağrılan metodun, nesnenin gerçek türüne göre çalışma zamanında belirlenmesi mekanizması.
- **Nasıl Çalışır**:
  1. Nesne bir vPtr içerir
  2. vPtr, sınıfın vTable'ını işaret eder
  3. Metot çağrısı sırasında, vTable'dan ilgili metodun adresi alınır
  4. Bulunan adresteki kod çalıştırılır
- **Temel Kural**: Dinamik dağıtım yalnızca işaretçiler veya referanslar aracılığıyla çağrılır.
- **Örnek**:
  ```cpp
  void Bureaucrat::executeForm(AForm const &form) {
      form.execute(*this); // form'un gerçek türüne göre doğru execute çağrılır
  }
  ```

## Özet ve İlişkiler

- **Sanal fonksiyonlar**, polimorfizmi gerçekleştirmek için C++'ın sunduğu mekanizmadır
- **Dinamik dağıtım**, sanal fonksiyonların çağrılmasında kullanılan çalışma zamanı mekanizmasıdır
- **Override anahtar kelimesi**, sanal fonksiyon mekanizmasının güvenli kullanımını sağlar
- **Çalışma zamanı maliyeti**, vTable ve vPtr yapısından kaynaklanır
- **Polimorfizm**, tüm bu mekanizmaların getirdiği programlama paradigmasıdır






# C++ Sanal Fonksiyonlar ve Polimorfizm Notları

## 1. Sanal Fonksiyonlar (Virtual Functions)

- **Tanım**: `virtual` anahtar kelimesi ile işaretlenen ve türetilmiş sınıflar tarafından ezilebilen (override edilebilen) fonksiyonlardır.
- **Sözdizimi**: `virtual dönüş_tipi fonksiyon_adı(parametreler);`
- **Saf Sanal Fonksiyonlar**: `= 0` ifadesiyle tanımlanan ve türetilmiş sınıfların uygulamak zorunda olduğu fonksiyonlardır.
  ```cpp
  virtual void execute(Bureaucrat const &executor) const = 0;
  ```
- **Amaç**: Türetilmiş sınıflara, temel sınıfın işlevselliğini değiştirme imkanı sağlar.
- **Sanal Yıkıcılar**: Polimorfik sınıflarda bellek sızıntılarını önlemek için yıkıcı fonksiyonlar genellikle sanal olarak tanımlanır.
  ```cpp
  virtual ~AForm(); // Doğru yıkma sıralaması için
  ```

## 2. Çalışma Zamanı Maliyeti (Runtime Cost)

- **vTable (Sanal Fonksiyon Tablosu)**: Her sanal fonksiyona sahip sınıf için derleyici bir vTable oluşturur.
- **vPtr (Sanal İşaretçi)**: Sanal fonksiyona sahip her nesne, sınıfın vTable'ına işaret eden bir vPtr içerir.
- **Bellek Maliyeti**: 
  - Her polimorfik nesne için ek bir işaretçi boyutu (genellikle 4 veya 8 byte)
  - Her polimorfik sınıf için bir vTable
- **Performans Maliyeti**:
  - İlave bir işaretçi dereferans işlemi
  - Çağrı sırasında fonksiyon adresinin vTable'dan bulunması
  - İşlemci önbellek isabetlerinde potansiyel düşüş
- **Not**: Modern işlemcilerde bu maliyet genellikle göz ardı edilebilir düzeydedir.

## 3. Polimorfizm (Polymorphism)

- **Tanım**: Farklı türlerin, aynı arayüz üzerinden farklı davranışlar sergileyebilme yeteneğidir.
- **Türleri**:
  - **Statik (Derleme Zamanı)**: Fonksiyon veya operatör aşırı yükleme
  - **Dinamik (Çalışma Zamanı)**: Sanal fonksiyonlar aracılığıyla
- **Avantajları**:
  - Kod yeniden kullanılabilirliği
  - Genişletilebilirlik
  - Soyutlama
- **Örnek**:
  ```cpp
  AForm* form = new ShrubberyCreationForm("Garden");
  form->execute(bureaucrat); // ShrubberyCreationForm'un execute metodu çağrılır
  ```

## 4. Override Anahtar Kelimesi

- **Tanım**: C++11 ile eklenen, bir metodun üst sınıftaki sanal metodu ezdiğini açıkça belirten anahtar kelime.
- **Amaç**: Derleme zamanında hata yakalama sağlar:
  - İmza uyuşmazlıklarını yakalar
  - Ezilemeyecek metotları ezme girişimlerini engeller
- **Kullanım**:
  ```cpp
  class ShrubberyCreationForm : public AForm {
  public:
      void execute(Bureaucrat const &executor) const override;
  };
  ```
- **Faydaları**:
  - Kodun kendini belgelendirmesi
  - Yeniden düzenleme sırasında güvenlik
  - İmza değişikliklerinde otomatik uyum kontrolü

## 5. Dinamik Dağıtım (Dynamic Dispatch)

- **Tanım**: Çağrılan metodun, nesnenin gerçek türüne göre çalışma zamanında belirlenmesi mekanizması.
- **Nasıl Çalışır**:
  1. Nesne bir vPtr içerir
  2. vPtr, sınıfın vTable'ını işaret eder
  3. Metot çağrısı sırasında, vTable'dan ilgili metodun adresi alınır
  4. Bulunan adresteki kod çalıştırılır
- **Temel Kural**: Dinamik dağıtım yalnızca işaretçiler veya referanslar aracılığıyla çağrılır.
- **Örnek**:
  ```cpp
  void Bureaucrat::executeForm(AForm const &form) {
      form.execute(*this); // form'un gerçek türüne göre doğru execute çağrılır
  }
  ```

## Özet ve İlişkiler

- **Sanal fonksiyonlar**, polimorfizmi gerçekleştirmek için C++'ın sunduğu mekanizmadır
- **Dinamik dağıtım**, sanal fonksiyonların çağrılmasında kullanılan çalışma zamanı mekanizmasıdır
- **Override anahtar kelimesi**, sanal fonksiyon mekanizmasının güvenli kullanımını sağlar
- **Çalışma zamanı maliyeti**, vTable ve vPtr yapısından kaynaklanır
- **Polimorfizm**, tüm bu mekanizmaların getirdiği programlama paradigmasıdır







# C++98'de İstisnalar (Try-Throw-Catch) Detaylı Açıklama

## 1. Try Bloğu - İstisna Yakalamaya Hazırlık

**Amaç:** İstisna fırlatılabilecek potansiyel kod bloğunu belirler.

**Neden Kullanırız:**
- Hata olabilecek kod bölümlerini izole eder
- İstisnaların kontrollü bir şekilde yönetilmesini sağlar
- Hata işleme mantığını normal iş mantığından ayırır

**Örnekteki Kullanımı:**
```cpp
try {
    if (grade > 150)
        throw (GradeTooLowException());
    // Bu kısım potansiyel olarak istisna fırlatabilir
}
```

## 2. Throw İfadesi - İstisna Fırlatma

**Amaç:** Normal program akışını kesip bir hata durumu bildirir.

**Neden Kullanırız:**
- Programın normal akışını sürdüremeyeceği durumları belirtir
- Hatanın türünü ve sebebini iletebilir
- Hata işlemeyi çağıran fonksiyonlara iletebilir (hata propagasyonu)

**Örnekteki Kullanımı:**
```cpp
if (grade > 150)
    throw (GradeTooLowException()); // Geçersiz durum - istisna fırlat
```

**Throw Mekanizması:**
1. Program akışı hemen durdurulur
2. Otomatik değişkenler için "stack unwinding" başlar (yıkıcı fonksiyonlar çağrılır)
3. Çağrı yığınında (call stack) en yakın uygun catch bloğu aranır

## 3. Catch Bloğu - İstisna İşleme

**Amaç:** Belirli türdeki istisnaları yakalayıp işler.

**Neden Kullanırız:**
- İstisnaları türlerine göre özel olarak işleyebiliriz
- Programın kontrollü bir şekilde toparlanmasını sağlar
- Kullanıcıya anlamlı hata mesajları gösterebiliriz

**Örnekteki Kullanımı:**
```cpp
catch (const std::exception &e) {
    std::cout << e.what() << std::endl; // Hatayı kullanıcıya bil̇dir
}
```

**Yakalama Sırası:**
- Catch blokları, belirtilen sırayla kontrol edilir
- En spesifik istisnalar önce, genel istisnalar sonra yazılmalıdır
- `catch(...)` - tüm istisnaları yakalar (son çare olarak kullanılır)

## 4. İstisna Hiyerarşisi

**Standard İstisnalar:**
```
std::exception (taban sınıf)
  ├── std::logic_error
  │     ├── std::invalid_argument
  │     ├── std::domain_error
  │     └── ...
  └── std::runtime_error
        ├── std::overflow_error
        ├── std::range_error
        └── ...
```

**Özel İstisnalar:**
```cpp
class GradeTooHighException : public std::exception {
    const char* what() const throw(); // throw() belirteci önemli
};
```

## 5. Throw Belirteci - C++98'e Özgü

**Amaç:** Bir fonksiyonun hangi istisnaları fırlatabileceğini belirtir.

**Kullanımı:**
```cpp
const char* what() const throw(); // Hiçbir istisna fırlatmaz
void func() throw(std::exception); // Sadece std::exception fırlatabilir
```

**Neden Kullanırız:**
- Derleyici kontrolü sağlar
- Fonksiyon sözleşmesini belirler
- Dokümantasyon sağlar
- C++11'de `noexcept` ile değiştirildi

## 6. İstisnaların Avantajları ve Kullanım Nedenleri

1. **Hata İşlemeyi Ayırma:** Normal kod ve hata işleme kodunu ayırır
   ```cpp
   // Hatasız kod; net ve anlaşılır
   void signForm(Form &f) {
       f.beSigned(*this);
       std::cout << this->name << " signed " << f.getName() << std::endl;
   }
   ```

2. **Propagasyon:** Hatalar çağrı yığınında yukarıya iletilebilir
   ```cpp
   // Fonksiyon A -> Fonksiyon B -> Fonksiyon C
   // Fonksiyon C'de oluşan hata, A'ya kadar iletilebilir
   ```

3. **Tip Güvenliği:** Farklı türdeki hatalar için farklı işlemler yapılabilir
   ```cpp
   catch (GradeTooHighException &e) { /* özel işlem */ }
   catch (GradeTooLowException &e) { /* farklı işlem */ }
   ```

4. **Kaçışsız Hata İletimi:** Hata durumlarını görmezden gelmek zorlaşır
   ```cpp
   // Dönüş değerini kontrol etmeyi unutabilirsiniz
   bool result = someFunction();
   
   // Ama istisnaları görmezden gelemezsiniz
   try { someFunction(); } catch (...) { /* hata işleme zorunlu */ }
   ```

## 7. İstisna Güvenliği

**Temel Garanti:** İstisnalar fırlatıldığında programın tutarlı durumda kalması

```cpp
Bureaucrat::increment() {
    this->grade--;
    
    try {
        if (grade < 1)
            throw(GradeTooHighException());
    } catch (const std::exception &e) {
        this->grade++; // Geri alarak tutarlı duruma dön
        std::cout << e.what() << std::endl;
    }
}
```

**RAII (Resource Acquisition Is Initialization):** İstisnalarda kaynak sızıntısını önleyen önemli desen

```cpp
{
    // İstisna fırlatılsa bile otomatik olarak kapatılır
    std::ifstream file("example.txt");
    // file kullanımı...
} // Kapsam dışına çıkınca otomatik kapatılır
```






class GradeTooHighException : public std::out_of_range {
public:
    GradeTooHighException() : std::out_of_range("Grade out of range: too high") {}
};

class GradeTooLowException : public std::invalid_argument {
public:
    GradeTooLowException() : std::invalid_argument("Grade too low (must be at least 150)") {}
};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
    




# Can I Use std::out_of_range According to the Requirements?

Based on the exercise requirements in 5.md, there's nothing that explicitly prohibits using standard exception classes like `std::out_of_range` as base classes for your custom exceptions. However, there are some considerations:

## What the Requirements State:
- The exceptions must be named `Bureaucrat::GradeTooHighException` and `Bureaucrat::GradeTooLowException`
- Exception classes don't need to follow Orthodox Canonical Form
- Exceptions must be catchable with `catch (std::exception & e)`

## Technical Options:
You have two valid approaches:

1. **Direct inheritance (typical approach):**
   ```cpp
   class GradeTooHighException : public std::exception {
   public:
       virtual const char* what() const throw();
   };
   ```

2. **Inheriting from specific standard exceptions:**
   ```cpp
   class GradeTooHighException : public std::out_of_range {
   public:
       GradeTooHighException() : std::out_of_range("Grade too high") {}
   };
   ```

## Recommendation:
While using `std::out_of_range` is technically valid, I recommend the direct inheritance approach because:

1. It's more consistent with the educational purpose of the exercise
2. It's the conventional pattern typically used for these C++98 exercises
3. Most example code and reference solutions use this approach

The main advantage of using `std::out_of_range` would be simplicity (no need to implement `what()`), but this isn't a complex requirement, and implementing it yourself provides better learning value.








UNUTMUSUM