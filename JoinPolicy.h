#pragma once

class JoinPolicy {};

class MandatesJoinPolicy : public JoinPolicy {}; //subclass of JoinPolicy

class LastOfferJoinPolicy : public JoinPolicy {}; //subclass of JoinPolicy