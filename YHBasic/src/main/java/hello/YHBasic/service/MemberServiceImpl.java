package hello.YHBasic.service;

import hello.YHBasic.domain.Member;
import hello.YHBasic.repository.MemberRepository;
import hello.YHBasic.repository.MemoryMemberRepository;

public class MemberServiceImpl implements MemberService {

    private final MemberRepository memberRepository = new MemoryMemberRepository();

    @Override
    public void join(Member member) {
        memberRepository.save(member);
    }

    @Override
    public Member findMember(Long memberId) {
        return memberRepository.findById(memberId);
    }
}