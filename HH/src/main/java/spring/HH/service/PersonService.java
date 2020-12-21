package spring.HH.service;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.domain.Block;
import spring.HH.domain.Person;
import spring.HH.domain.dto.PersonDto;
import spring.HH.repository.BlockRepository;
import spring.HH.repository.PersonRepository;

import java.util.List;
import java.util.stream.Collectors;

@Service
@Slf4j
public class PersonService {

    @Autowired
    private PersonRepository personRepository;

    public List<Person> getPeopleByName(String name) {

        return personRepository.findByName(name);
    }

    @Transactional(readOnly = true)
    public Person getPerson(Long id) {
        Person person = personRepository.findById(id).orElse(null);

        log.info("person : {}", person);

        return person;
    }

    @Transactional
    public void put(Person person) {
        personRepository.save(person);
    }

    @Transactional
    public void modify(Long id, PersonDto personDto) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Id not exists."));

        if (!person.getName().equals(personDto.getName())) {
            throw new RuntimeException("Name is different.");
        }

        person.set(personDto);

        personRepository.save(person);
    }

    @Transactional
    public void modify(Long id, String name) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Id is not exist."));

        person.setName(name);

        personRepository.save(person);
    }

    public void delete(Long id) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Id is not exist."));

        person.setDeleted(true);

        personRepository.save(person);
    }
}
