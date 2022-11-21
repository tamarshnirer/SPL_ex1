#pragma once

class JoinPolicy {
    public:
        JoinPolicy();
        virtual Agent* join(Party mParty);
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual Agent* join(Party mParty);

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual Agent* join(Party mParty);
};